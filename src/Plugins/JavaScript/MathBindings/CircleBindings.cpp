// For conditions of distribution and use, see copyright notice in LICENSE
// This file has been autogenerated with BindingsGenerator

#include "StableHeaders.h"
#include "CoreTypes.h"
#include "BindingsHelpers.h"
#include "Geometry/Circle.h"
#include "Geometry/Plane.h"
#include "Math/float3x3.h"
#include "Math/float3x4.h"
#include "Math/float4x4.h"
#include "Math/Quat.h"
#include "Geometry/Line.h"
#include "Geometry/LineSegment.h"
#include "Geometry/Ray.h"
#include "Geometry/OBB.h"
#include "Geometry/AABB.h"

using namespace std;

namespace JSBindings
{

extern const char* Plane_Id;
extern const char* float3x3_Id;
extern const char* float3x4_Id;
extern const char* float4x4_Id;
extern const char* Quat_Id;
extern const char* Line_Id;
extern const char* LineSegment_Id;
extern const char* Ray_Id;
extern const char* OBB_Id;
extern const char* AABB_Id;

duk_ret_t Plane_Dtor(duk_context* ctx);
duk_ret_t float3x3_Dtor(duk_context* ctx);
duk_ret_t float3x4_Dtor(duk_context* ctx);
duk_ret_t float4x4_Dtor(duk_context* ctx);
duk_ret_t Quat_Dtor(duk_context* ctx);
duk_ret_t Line_Dtor(duk_context* ctx);
duk_ret_t LineSegment_Dtor(duk_context* ctx);
duk_ret_t Ray_Dtor(duk_context* ctx);
duk_ret_t OBB_Dtor(duk_context* ctx);
duk_ret_t AABB_Dtor(duk_context* ctx);

const char* Circle_Id = "Circle";

duk_ret_t Circle_Dtor(duk_context* ctx)
{
    Circle* obj = GetObject<Circle>(ctx, 0, Circle_Id);
    if (obj)
    {
        delete obj;
        SetObject(ctx, 0, 0, Circle_Id);
    }
    return 0;
}

static duk_ret_t Circle_Set_r(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    float r = (float)duk_require_number(ctx, 0);
    thisObj->r = r;
    return 0;
}

static duk_ret_t Circle_Get_r(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    duk_push_number(ctx, thisObj->r);
    return 1;
}

static duk_ret_t Circle_Ctor(duk_context* ctx)
{
    Circle* newObj = new Circle();
    PushConstructorResult<Circle>(ctx, newObj, Circle_Id, Circle_Dtor);
    return 0;
}

static duk_ret_t Circle_ContainingPlane(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    Plane ret = thisObj->ContainingPlane();
    PushValueObjectCopy<Plane>(ctx, ret, Plane_Id, Plane_Dtor);
    return 1;
}

static duk_ret_t Circle_Transform_float3x3(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    float3x3* transform = GetCheckedObject<float3x3>(ctx, 0, float3x3_Id);
    thisObj->Transform(*transform);
    return 0;
}

static duk_ret_t Circle_Transform_float3x4(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    float3x4* transform = GetCheckedObject<float3x4>(ctx, 0, float3x4_Id);
    thisObj->Transform(*transform);
    return 0;
}

static duk_ret_t Circle_Transform_float4x4(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    float4x4* transform = GetCheckedObject<float4x4>(ctx, 0, float4x4_Id);
    thisObj->Transform(*transform);
    return 0;
}

static duk_ret_t Circle_Transform_Quat(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    Quat* transform = GetCheckedObject<Quat>(ctx, 0, Quat_Id);
    thisObj->Transform(*transform);
    return 0;
}

static duk_ret_t Circle_Intersects_Plane(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    Plane* plane = GetCheckedObject<Plane>(ctx, 0, Plane_Id);
    int ret = thisObj->Intersects(*plane);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Circle_IntersectsDisc_Line(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    Line* line = GetCheckedObject<Line>(ctx, 0, Line_Id);
    bool ret = thisObj->IntersectsDisc(*line);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Circle_IntersectsDisc_LineSegment(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    LineSegment* lineSegment = GetCheckedObject<LineSegment>(ctx, 0, LineSegment_Id);
    bool ret = thisObj->IntersectsDisc(*lineSegment);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Circle_IntersectsDisc_Ray(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    Ray* ray = GetCheckedObject<Ray>(ctx, 0, Ray_Id);
    bool ret = thisObj->IntersectsDisc(*ray);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Circle_ToString(duk_context* ctx)
{
    Circle* thisObj = GetThisObject<Circle>(ctx, Circle_Id);
    std::string ret = thisObj->ToString();
    duk_push_string(ctx, ret.c_str());
    return 1;
}

static duk_ret_t Circle_Transform_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 1 && GetObject<float3x3>(ctx, 0, float3x3_Id))
        return Circle_Transform_float3x3(ctx);
    if (numArgs == 1 && GetObject<float3x4>(ctx, 0, float3x4_Id))
        return Circle_Transform_float3x4(ctx);
    if (numArgs == 1 && GetObject<float4x4>(ctx, 0, float4x4_Id))
        return Circle_Transform_float4x4(ctx);
    if (numArgs == 1 && GetObject<Quat>(ctx, 0, Quat_Id))
        return Circle_Transform_Quat(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Circle_IntersectsDisc_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 1 && GetObject<Line>(ctx, 0, Line_Id))
        return Circle_IntersectsDisc_Line(ctx);
    if (numArgs == 1 && GetObject<LineSegment>(ctx, 0, LineSegment_Id))
        return Circle_IntersectsDisc_LineSegment(ctx);
    if (numArgs == 1 && GetObject<Ray>(ctx, 0, Ray_Id))
        return Circle_IntersectsDisc_Ray(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static const duk_function_list_entry Circle_Functions[] = {
    {"ContainingPlane", Circle_ContainingPlane, 0}
    ,{"Transform", Circle_Transform_Selector, DUK_VARARGS}
    ,{"Intersects", Circle_Intersects_Plane, 1}
    ,{"IntersectsDisc", Circle_IntersectsDisc_Selector, DUK_VARARGS}
    ,{"ToString", Circle_ToString, 0}
    ,{nullptr, nullptr, 0}
};

void Expose_Circle(duk_context* ctx)
{
    duk_push_c_function(ctx, Circle_Ctor, DUK_VARARGS);
    duk_push_object(ctx);
    duk_put_function_list(ctx, -1, Circle_Functions);
    DefineProperty(ctx, "r", Circle_Get_r, Circle_Set_r);
    duk_put_prop_string(ctx, -2, "prototype");
    duk_put_global_string(ctx, Circle_Id);
}

}
