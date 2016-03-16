// For conditions of distribution and use, see copyright notice in LICENSE
// This file has been autogenerated with BindingsGenerator

#include "StableHeaders.h"
#include "CoreTypes.h"
#include "JavaScriptInstance.h"
#include "LoggingFunctions.h"
#include "Scene/IComponent.h"

#ifdef _MSC_VER
#pragma warning(disable: 4800)
#endif

#include "Scene/Entity.h"
#include "Framework/Framework.h"
#include "Scene/Scene.h"


using namespace Tundra;
using namespace std;

namespace JSBindings
{



static const char* IComponent_ID = "IComponent";

const char* SignalWrapper_IComponent_ComponentNameChanged_ID = "SignalWrapper_IComponent_ComponentNameChanged";

class SignalWrapper_IComponent_ComponentNameChanged
{
public:
    SignalWrapper_IComponent_ComponentNameChanged(Object* owner, Signal2< const String &, const String & >* signal) :
        owner_(owner),
        signal_(signal)
    {
    }

    WeakPtr<Object> owner_;
    Signal2< const String &, const String & >* signal_;
};

class SignalReceiver_IComponent_ComponentNameChanged : public SignalReceiver
{
public:
    void OnSignal(const String & param0, const String & param1)
    {
        duk_context* ctx = ctx_;
        duk_push_global_object(ctx);
        duk_get_prop_string(ctx, -1, "_OnSignal");
        duk_remove(ctx, -2);
        duk_push_number(ctx, (size_t)key_);
        duk_push_array(ctx);
        duk_push_string(ctx, param0.CString());
        duk_put_prop_index(ctx, -2, 0);
        duk_push_string(ctx, param1.CString());
        duk_put_prop_index(ctx, -2, 1);
        bool success = duk_pcall(ctx, 2) == 0;
        if (!success) LogError("[JavaScript] OnSignal: " + String(duk_safe_to_string(ctx, -1)));
        duk_pop(ctx);
    }
};

static duk_ret_t SignalWrapper_IComponent_ComponentNameChanged_Finalizer(duk_context* ctx)
{
    FinalizeValueObject<SignalWrapper_IComponent_ComponentNameChanged>(ctx, SignalWrapper_IComponent_ComponentNameChanged_ID);
    return 0;
}

static duk_ret_t SignalWrapper_IComponent_ComponentNameChanged_Connect(duk_context* ctx)
{
    SignalWrapper_IComponent_ComponentNameChanged* wrapper = GetThisValueObject<SignalWrapper_IComponent_ComponentNameChanged>(ctx, SignalWrapper_IComponent_ComponentNameChanged_ID);
    if (!wrapper->owner_) return 0;
    HashMap<void*, SharedPtr<SignalReceiver> >& signalReceivers = JavaScriptInstance::InstanceFromContext(ctx)->SignalReceivers();
    if (signalReceivers.Find(wrapper->signal_) == signalReceivers.End())
    {
        SignalReceiver_IComponent_ComponentNameChanged* receiver = new SignalReceiver_IComponent_ComponentNameChanged();
        receiver->ctx_ = ctx;
        receiver->key_ = wrapper->signal_;
        wrapper->signal_->Connect(receiver, &SignalReceiver_IComponent_ComponentNameChanged::OnSignal);
        signalReceivers[wrapper->signal_] = receiver;
    }
    CallConnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_IComponent_ComponentNameChanged_Disconnect(duk_context* ctx)
{
    SignalWrapper_IComponent_ComponentNameChanged* wrapper = GetThisValueObject<SignalWrapper_IComponent_ComponentNameChanged>(ctx, SignalWrapper_IComponent_ComponentNameChanged_ID);
    if (!wrapper->owner_) return 0;
    CallDisconnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_IComponent_ComponentNameChanged_Emit(duk_context* ctx)
{
    SignalWrapper_IComponent_ComponentNameChanged* wrapper = GetThisValueObject<SignalWrapper_IComponent_ComponentNameChanged>(ctx, SignalWrapper_IComponent_ComponentNameChanged_ID);
    if (!wrapper->owner_) return 0;
    String param0 = duk_require_string(ctx, 0);
    String param1 = duk_require_string(ctx, 1);
    wrapper->signal_->Emit(param0, param1);
    return 0;
}

static duk_ret_t IComponent_Get_ComponentNameChanged(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    SignalWrapper_IComponent_ComponentNameChanged* wrapper = new SignalWrapper_IComponent_ComponentNameChanged(thisObj, &thisObj->ComponentNameChanged);
    PushValueObject(ctx, wrapper, SignalWrapper_IComponent_ComponentNameChanged_ID, SignalWrapper_IComponent_ComponentNameChanged_Finalizer, false);
    duk_push_c_function(ctx, SignalWrapper_IComponent_ComponentNameChanged_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Connect");
    duk_push_c_function(ctx, SignalWrapper_IComponent_ComponentNameChanged_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Disconnect");
    duk_push_c_function(ctx, SignalWrapper_IComponent_ComponentNameChanged_Emit, 2);
    duk_put_prop_string(ctx, -2, "Emit");
    return 1;
}

const char* SignalWrapper_IComponent_ParentEntitySet_ID = "SignalWrapper_IComponent_ParentEntitySet";

class SignalWrapper_IComponent_ParentEntitySet
{
public:
    SignalWrapper_IComponent_ParentEntitySet(Object* owner, Signal0< void >* signal) :
        owner_(owner),
        signal_(signal)
    {
    }

    WeakPtr<Object> owner_;
    Signal0< void >* signal_;
};

class SignalReceiver_IComponent_ParentEntitySet : public SignalReceiver
{
public:
    void OnSignal()
    {
        duk_context* ctx = ctx_;
        duk_push_global_object(ctx);
        duk_get_prop_string(ctx, -1, "_OnSignal");
        duk_remove(ctx, -2);
        duk_push_number(ctx, (size_t)key_);
        duk_push_array(ctx);
        bool success = duk_pcall(ctx, 2) == 0;
        if (!success) LogError("[JavaScript] OnSignal: " + String(duk_safe_to_string(ctx, -1)));
        duk_pop(ctx);
    }
};

static duk_ret_t SignalWrapper_IComponent_ParentEntitySet_Finalizer(duk_context* ctx)
{
    FinalizeValueObject<SignalWrapper_IComponent_ParentEntitySet>(ctx, SignalWrapper_IComponent_ParentEntitySet_ID);
    return 0;
}

static duk_ret_t SignalWrapper_IComponent_ParentEntitySet_Connect(duk_context* ctx)
{
    SignalWrapper_IComponent_ParentEntitySet* wrapper = GetThisValueObject<SignalWrapper_IComponent_ParentEntitySet>(ctx, SignalWrapper_IComponent_ParentEntitySet_ID);
    if (!wrapper->owner_) return 0;
    HashMap<void*, SharedPtr<SignalReceiver> >& signalReceivers = JavaScriptInstance::InstanceFromContext(ctx)->SignalReceivers();
    if (signalReceivers.Find(wrapper->signal_) == signalReceivers.End())
    {
        SignalReceiver_IComponent_ParentEntitySet* receiver = new SignalReceiver_IComponent_ParentEntitySet();
        receiver->ctx_ = ctx;
        receiver->key_ = wrapper->signal_;
        wrapper->signal_->Connect(receiver, &SignalReceiver_IComponent_ParentEntitySet::OnSignal);
        signalReceivers[wrapper->signal_] = receiver;
    }
    CallConnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_IComponent_ParentEntitySet_Disconnect(duk_context* ctx)
{
    SignalWrapper_IComponent_ParentEntitySet* wrapper = GetThisValueObject<SignalWrapper_IComponent_ParentEntitySet>(ctx, SignalWrapper_IComponent_ParentEntitySet_ID);
    if (!wrapper->owner_) return 0;
    CallDisconnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_IComponent_ParentEntitySet_Emit(duk_context* ctx)
{
    SignalWrapper_IComponent_ParentEntitySet* wrapper = GetThisValueObject<SignalWrapper_IComponent_ParentEntitySet>(ctx, SignalWrapper_IComponent_ParentEntitySet_ID);
    if (!wrapper->owner_) return 0;
    wrapper->signal_->Emit();
    return 0;
}

static duk_ret_t IComponent_Get_ParentEntitySet(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    SignalWrapper_IComponent_ParentEntitySet* wrapper = new SignalWrapper_IComponent_ParentEntitySet(thisObj, &thisObj->ParentEntitySet);
    PushValueObject(ctx, wrapper, SignalWrapper_IComponent_ParentEntitySet_ID, SignalWrapper_IComponent_ParentEntitySet_Finalizer, false);
    duk_push_c_function(ctx, SignalWrapper_IComponent_ParentEntitySet_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Connect");
    duk_push_c_function(ctx, SignalWrapper_IComponent_ParentEntitySet_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Disconnect");
    duk_push_c_function(ctx, SignalWrapper_IComponent_ParentEntitySet_Emit, 0);
    duk_put_prop_string(ctx, -2, "Emit");
    return 1;
}

const char* SignalWrapper_IComponent_ParentEntityAboutToBeDetached_ID = "SignalWrapper_IComponent_ParentEntityAboutToBeDetached";

class SignalWrapper_IComponent_ParentEntityAboutToBeDetached
{
public:
    SignalWrapper_IComponent_ParentEntityAboutToBeDetached(Object* owner, Signal0< void >* signal) :
        owner_(owner),
        signal_(signal)
    {
    }

    WeakPtr<Object> owner_;
    Signal0< void >* signal_;
};

class SignalReceiver_IComponent_ParentEntityAboutToBeDetached : public SignalReceiver
{
public:
    void OnSignal()
    {
        duk_context* ctx = ctx_;
        duk_push_global_object(ctx);
        duk_get_prop_string(ctx, -1, "_OnSignal");
        duk_remove(ctx, -2);
        duk_push_number(ctx, (size_t)key_);
        duk_push_array(ctx);
        bool success = duk_pcall(ctx, 2) == 0;
        if (!success) LogError("[JavaScript] OnSignal: " + String(duk_safe_to_string(ctx, -1)));
        duk_pop(ctx);
    }
};

static duk_ret_t SignalWrapper_IComponent_ParentEntityAboutToBeDetached_Finalizer(duk_context* ctx)
{
    FinalizeValueObject<SignalWrapper_IComponent_ParentEntityAboutToBeDetached>(ctx, SignalWrapper_IComponent_ParentEntityAboutToBeDetached_ID);
    return 0;
}

static duk_ret_t SignalWrapper_IComponent_ParentEntityAboutToBeDetached_Connect(duk_context* ctx)
{
    SignalWrapper_IComponent_ParentEntityAboutToBeDetached* wrapper = GetThisValueObject<SignalWrapper_IComponent_ParentEntityAboutToBeDetached>(ctx, SignalWrapper_IComponent_ParentEntityAboutToBeDetached_ID);
    if (!wrapper->owner_) return 0;
    HashMap<void*, SharedPtr<SignalReceiver> >& signalReceivers = JavaScriptInstance::InstanceFromContext(ctx)->SignalReceivers();
    if (signalReceivers.Find(wrapper->signal_) == signalReceivers.End())
    {
        SignalReceiver_IComponent_ParentEntityAboutToBeDetached* receiver = new SignalReceiver_IComponent_ParentEntityAboutToBeDetached();
        receiver->ctx_ = ctx;
        receiver->key_ = wrapper->signal_;
        wrapper->signal_->Connect(receiver, &SignalReceiver_IComponent_ParentEntityAboutToBeDetached::OnSignal);
        signalReceivers[wrapper->signal_] = receiver;
    }
    CallConnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_IComponent_ParentEntityAboutToBeDetached_Disconnect(duk_context* ctx)
{
    SignalWrapper_IComponent_ParentEntityAboutToBeDetached* wrapper = GetThisValueObject<SignalWrapper_IComponent_ParentEntityAboutToBeDetached>(ctx, SignalWrapper_IComponent_ParentEntityAboutToBeDetached_ID);
    if (!wrapper->owner_) return 0;
    CallDisconnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_IComponent_ParentEntityAboutToBeDetached_Emit(duk_context* ctx)
{
    SignalWrapper_IComponent_ParentEntityAboutToBeDetached* wrapper = GetThisValueObject<SignalWrapper_IComponent_ParentEntityAboutToBeDetached>(ctx, SignalWrapper_IComponent_ParentEntityAboutToBeDetached_ID);
    if (!wrapper->owner_) return 0;
    wrapper->signal_->Emit();
    return 0;
}

static duk_ret_t IComponent_Get_ParentEntityAboutToBeDetached(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    SignalWrapper_IComponent_ParentEntityAboutToBeDetached* wrapper = new SignalWrapper_IComponent_ParentEntityAboutToBeDetached(thisObj, &thisObj->ParentEntityAboutToBeDetached);
    PushValueObject(ctx, wrapper, SignalWrapper_IComponent_ParentEntityAboutToBeDetached_ID, SignalWrapper_IComponent_ParentEntityAboutToBeDetached_Finalizer, false);
    duk_push_c_function(ctx, SignalWrapper_IComponent_ParentEntityAboutToBeDetached_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Connect");
    duk_push_c_function(ctx, SignalWrapper_IComponent_ParentEntityAboutToBeDetached_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Disconnect");
    duk_push_c_function(ctx, SignalWrapper_IComponent_ParentEntityAboutToBeDetached_Emit, 0);
    duk_put_prop_string(ctx, -2, "Emit");
    return 1;
}

static duk_ret_t IComponent_TypeName(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    const String & ret = thisObj->TypeName();
    duk_push_string(ctx, ret.CString());
    return 1;
}

static duk_ret_t IComponent_TypeId(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    u32 ret = thisObj->TypeId();
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_Name(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    const String & ret = thisObj->Name();
    duk_push_string(ctx, ret.CString());
    return 1;
}

static duk_ret_t IComponent_SetName_String(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    String name = duk_require_string(ctx, 0);
    thisObj->SetName(name);
    return 0;
}

static duk_ret_t IComponent_SetParentEntity_Entity(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    Entity* entity = GetWeakObject<Entity>(ctx, 0);
    thisObj->SetParentEntity(entity);
    return 0;
}

static duk_ret_t IComponent_SetReplicated_bool(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    bool enable = duk_require_boolean(ctx, 0);
    thisObj->SetReplicated(enable);
    return 0;
}

static duk_ret_t IComponent_GetFramework(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    Framework * ret = thisObj->GetFramework();
    PushWeakObject(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_IsReplicated(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    bool ret = thisObj->IsReplicated();
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_IsLocal(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    bool ret = thisObj->IsLocal();
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_IsUnacked(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    bool ret = thisObj->IsUnacked();
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_SetUpdateMode_AttributeChange__Type(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    AttributeChange::Type defaultmode = (AttributeChange::Type)(int)duk_require_number(ctx, 0);
    thisObj->SetUpdateMode(defaultmode);
    return 0;
}

static duk_ret_t IComponent_UpdateMode(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    AttributeChange::Type ret = thisObj->UpdateMode();
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_Id(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    component_id_t ret = thisObj->Id();
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_SupportsDynamicAttributes(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    bool ret = thisObj->SupportsDynamicAttributes();
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_NumAttributes(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    int ret = thisObj->NumAttributes();
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_NumStaticAttributes(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    int ret = thisObj->NumStaticAttributes();
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_EmitAttributeChanged_String_AttributeChange__Type(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    String attributeName = duk_require_string(ctx, 0);
    AttributeChange::Type change = (AttributeChange::Type)(int)duk_require_number(ctx, 1);
    thisObj->EmitAttributeChanged(attributeName, change);
    return 0;
}

static duk_ret_t IComponent_ComponentChanged_AttributeChange__Type(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    AttributeChange::Type change = (AttributeChange::Type)(int)duk_require_number(ctx, 0);
    thisObj->ComponentChanged(change);
    return 0;
}

static duk_ret_t IComponent_ParentEntity(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    Entity * ret = thisObj->ParentEntity();
    PushWeakObject(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_ParentScene(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    Scene * ret = thisObj->ParentScene();
    PushWeakObject(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_SetTemporary_bool(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    bool enable = duk_require_boolean(ctx, 0);
    thisObj->SetTemporary(enable);
    return 0;
}

static duk_ret_t IComponent_IsTemporary(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    bool ret = thisObj->IsTemporary();
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_ViewEnabled(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    bool ret = thisObj->ViewEnabled();
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_AttributeNames(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    StringVector ret = thisObj->AttributeNames();
    PushStringVector(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_AttributeIds(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    StringVector ret = thisObj->AttributeIds();
    PushStringVector(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_ShouldBeSerialized_bool_bool(duk_context* ctx)
{
    IComponent* thisObj = GetThisWeakObject<IComponent>(ctx);
    bool serializeTemporary = duk_require_boolean(ctx, 0);
    bool serializeLocal = duk_require_boolean(ctx, 1);
    bool ret = thisObj->ShouldBeSerialized(serializeTemporary, serializeLocal);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t IComponent_EnsureTypeNameWithoutPrefix_Static_String(duk_context* ctx)
{
    String tn = duk_require_string(ctx, 0);
    String ret = IComponent::EnsureTypeNameWithoutPrefix(tn);
    duk_push_string(ctx, ret.CString());
    return 1;
}

static const duk_function_list_entry IComponent_Functions[] = {
    {"TypeName", IComponent_TypeName, 0}
    ,{"TypeId", IComponent_TypeId, 0}
    ,{"Name", IComponent_Name, 0}
    ,{"SetName", IComponent_SetName_String, 1}
    ,{"SetParentEntity", IComponent_SetParentEntity_Entity, 1}
    ,{"SetReplicated", IComponent_SetReplicated_bool, 1}
    ,{"GetFramework", IComponent_GetFramework, 0}
    ,{"IsReplicated", IComponent_IsReplicated, 0}
    ,{"IsLocal", IComponent_IsLocal, 0}
    ,{"IsUnacked", IComponent_IsUnacked, 0}
    ,{"SetUpdateMode", IComponent_SetUpdateMode_AttributeChange__Type, 1}
    ,{"UpdateMode", IComponent_UpdateMode, 0}
    ,{"Id", IComponent_Id, 0}
    ,{"SupportsDynamicAttributes", IComponent_SupportsDynamicAttributes, 0}
    ,{"NumAttributes", IComponent_NumAttributes, 0}
    ,{"NumStaticAttributes", IComponent_NumStaticAttributes, 0}
    ,{"EmitAttributeChanged", IComponent_EmitAttributeChanged_String_AttributeChange__Type, 2}
    ,{"ComponentChanged", IComponent_ComponentChanged_AttributeChange__Type, 1}
    ,{"ParentEntity", IComponent_ParentEntity, 0}
    ,{"ParentScene", IComponent_ParentScene, 0}
    ,{"SetTemporary", IComponent_SetTemporary_bool, 1}
    ,{"IsTemporary", IComponent_IsTemporary, 0}
    ,{"ViewEnabled", IComponent_ViewEnabled, 0}
    ,{"AttributeNames", IComponent_AttributeNames, 0}
    ,{"AttributeIds", IComponent_AttributeIds, 0}
    ,{"ShouldBeSerialized", IComponent_ShouldBeSerialized_bool_bool, 2}
    ,{nullptr, nullptr, 0}
};

static const duk_function_list_entry IComponent_StaticFunctions[] = {
    {"EnsureTypeNameWithoutPrefix", IComponent_EnsureTypeNameWithoutPrefix_Static_String, 1}
    ,{nullptr, nullptr, 0}
};

void Expose_IComponent(duk_context* ctx)
{
    duk_push_object(ctx);
    duk_put_function_list(ctx, -1, IComponent_StaticFunctions);
    duk_push_object(ctx);
    duk_put_function_list(ctx, -1, IComponent_Functions);
    DefineProperty(ctx, "ComponentNameChanged", IComponent_Get_ComponentNameChanged, nullptr);
    DefineProperty(ctx, "ParentEntitySet", IComponent_Get_ParentEntitySet, nullptr);
    DefineProperty(ctx, "ParentEntityAboutToBeDetached", IComponent_Get_ParentEntityAboutToBeDetached, nullptr);
    DefineProperty(ctx, "typeName", IComponent_TypeName, nullptr);
    DefineProperty(ctx, "typeId", IComponent_TypeId, nullptr);
    DefineProperty(ctx, "name", IComponent_Name, IComponent_SetName_String);
    DefineProperty(ctx, "replicated", IComponent_IsReplicated, IComponent_SetReplicated_bool);
    DefineProperty(ctx, "local", IComponent_IsLocal, nullptr);
    DefineProperty(ctx, "unacked", IComponent_IsUnacked, nullptr);
    DefineProperty(ctx, "updateMode", IComponent_UpdateMode, IComponent_SetUpdateMode_AttributeChange__Type);
    DefineProperty(ctx, "id", IComponent_Id, nullptr);
    DefineProperty(ctx, "temporary", IComponent_IsTemporary, IComponent_SetTemporary_bool);
    DefineProperty(ctx, "viewEnabled", IComponent_ViewEnabled, nullptr);
    duk_put_prop_string(ctx, -2, "prototype");
    duk_put_global_string(ctx, IComponent_ID);
}

}
