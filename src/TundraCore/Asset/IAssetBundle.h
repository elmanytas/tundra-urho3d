// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#include "TundraCoreApi.h"
#include "CoreTypes.h"
#include "AssetFwd.h"
#include "AssetReference.h"
#include "Signals.h"

#include <Urho3D/Core/Object.h>

namespace Tundra
{

/// Base class for all asset bundles that provide sub assets.
class TUNDRACORE_API IAssetBundle : public Object
{
    OBJECT(IAssetBundle);

public:
    IAssetBundle(AssetAPI *assetAPI, const String &type, const String &name);

    /// The base class destructor does nothing.
    virtual ~IAssetBundle() {}
    
    /// Returns true if this asset bundle is loaded.
    virtual bool IsLoaded() const = 0;

    /// Returns if the asset bundle requires a disk source to operate.
    /** @note Default implementation returns false. */
    virtual bool RequiresDiskSource() = 0;

    /// Loads this asset bundle from the disk source.
    /** @return Return true if loading can be done from disk source, false otherwise eg. if disk source is empty.
        @note Implementations need to emit Loaded when completed. Do not emit Failed if you return false, Failed signal is reserved
        when this function return true and asynch loading fails. */
    virtual bool DeserializeFromDiskSource() = 0;

    /// Loads this asset bundle by deserializing it from the given data.
    /** @return Return true if loading can be done from data, false otherwise.
        @note Implementations need to emit Loaded when completed. Do not emit Failed if you return false, Failed signal is reserved
        when this function return true and asynch loading fails. */
    virtual bool DeserializeFromData(const u8 *data, uint numBytes) = 0;

    /// Provides a sub asset data from this bundle.
    /** This function returns the raw data of the sub asset. If the asset cannot be found 
        or fails to be unpacked return a empty vector.
        @return Vector<u8> data. */
    virtual Vector<u8> GetSubAssetData(const String &subAssetName) = 0;

    /// Provides a sub asset disk source from this bundle.
    /** This function returns the disk source of the specified sub asset, this function will always be queried first by AssetAPI.
        If there is no available disk source empty string is returned. After this the GetSubAssetData will be queried.
        @return Absolute disk source path if available, empty string otherwise.*/
    virtual String GetSubAssetDiskSource(const String &subAssetName) = 0;

    /// Returns the sub asset count in this bundle.
    /** @return Count of the assets or -1 if count is unknown. */
    virtual int SubAssetCount() const { return -1; }

    /// Returns the type of this asset bundle. The type of an asset cannot change during the lifetime of the instance of an asset.
    String Type() const;

    /// Returns the unique name of this asset bundle. The name of an asset cannot change during the lifetime of the instance of an asset.
    String Name() const;

    /// Returns the asset storage this bundle was loaded from.
    AssetStoragePtr AssetStorage() const;

    /// Returns the asset provider this bundle was loaded from.
    AssetProviderPtr AssetProvider() const;

    /// Returns the absolute path name to the file that contains the disk-cached version of this asset.
    /** For some assets, this is the cache file containing this asset, but for assets from some providers (e.g. LocalAssetProvider),
        this is the actual source filename of the asset. */
    String DiskSource() const;

    /// Saves the provider this bundle was downloaded from. Intended to be only called internally by Asset API at bundle load time.
    void SetAssetProvider(AssetProviderPtr provider);

    /// Saves the storage this bundle was downloaded from. Intended to be only called internally by Asset API at bundle load time.
    void SetAssetStorage(AssetStoragePtr storage);

    /// Specifies the file from which this asset can be reloaded, if it is unloaded in between.
    void SetDiskSource(String diskSource);

    /// Unloads this asset bundle from memory.
    void Unload();

    /// Returns true if the asset is empty. An empty asset is unloaded, and has an empty disk source.
    bool IsEmpty() const;

    /// This signal is emitted when the bundle is loaded and ready to provide sub assets.
    Signal1<IAssetBundle*> Loaded;

    /// This signal is emitted when the contents of this asset is unloaded.
    Signal1<IAssetBundle*> Unloaded;

    /// This signal is emitted when a loading error occurs after the deserialize functions have returned true (asynch loading).
    Signal1<IAssetBundle*> Failed;

protected:
    /// Private function that implements this bundles unloading. Called from Unload().
    /** @note You don't need to unload the individual assets that the bundle introduced
        if they were loaded as IAssets that AssetAPI is aware of. IAsset unloading will take care of it. */
    virtual void DoUnload() = 0;

    /// AssetAPI ptr.
    AssetAPI *assetAPI_;

    /// Specifies the type of this asset.
    String type_;

    /// Specifies the name of this asset, which for most assets is the source URL ref of where the asset was loaded.
    String name_;

    /// This path specifies a local filename from which this asset can be reloaded if necessary.
    String diskSource_;

    /// Specifies the provider this asset was downloaded from. May be null.
    AssetProviderWeakPtr provider;

    /// Specifies the storage this asset was downloaded from. May be null.
    AssetStorageWeakPtr storage;
};

/// @cond PRIVATE

// Object for tracking asset bundle parent child relations. This class is for private AssetAPI usage only.
class AssetBundleMonitor : public RefCounted
{
public:
    AssetBundleMonitor(AssetAPI *owner, AssetTransferPtr bundleTransfer);
    ~AssetBundleMonitor();

    /// Adds transfer as a child sub asset transfer for monitoring.
    void AddSubAssetTransfer(AssetTransferPtr transfer);

    /// Returns existing transfer for a specific asset reference.
    AssetTransferPtr SubAssetTransfer(const String &fullSubAssetRef);
    
    /// Return all tracked child sub asset transfers.
    Vector<AssetTransferPtr> SubAssetTransfers();

    /// Return the bundles own asset transfer.
    AssetTransferPtr BundleTransfer();
    
    /// Return the bundles own asset reference.
    String BundleAssetRef();

private:
    String bundleRef_;
    AssetTransferPtr bundleTransfer_;
    Vector<AssetTransferPtr> childTransfers_;
    AssetAPI *assetAPI_;

    void BundleFailed(IAssetTransfer* transfer, String reason);
};

struct SubAssetLoader
{
    String parentBundleRef;
    AssetTransferPtr subAssetTransfer;

    SubAssetLoader()
    {
    }

    SubAssetLoader(const String &_parentBundleRef, const AssetTransferPtr &_subAssetTransfer) :
        parentBundleRef(_parentBundleRef),
        subAssetTransfer(_subAssetTransfer)
    {
    }
};
/// @endcond

}
