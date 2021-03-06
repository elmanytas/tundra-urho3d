// For conditions of distribution and use, see copyright notice in LICENSE

#include "StableHeaders.h"
#include "AssetAPI.h"
#include "AssetCache.h"
#include <Urho3D/Core/Profiler.h>
#include "LoggingFunctions.h"
#include "IParticleAsset.h"

#include <Urho3D/Graphics/ParticleEffect.h>

namespace Tundra
{

IParticleAsset::IParticleAsset(AssetAPI *owner, const String &type_, const String &name_) :
    IAsset(owner, type_, name_)
{
}

IParticleAsset::~IParticleAsset()
{
    Unload();
}

void IParticleAsset::DoUnload()
{
    foreach (SharedPtr<Urho3D::ParticleEffect> pe, particleEffects_)
        pe.Reset();

    particleEffects_.Clear();
}

bool IParticleAsset::IsLoaded() const
{
    return particleEffects_.Size() > 0;
}

}
