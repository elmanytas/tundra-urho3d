setlocal EnableDelayedExpansion

cd..
doxygen UrhoRendererBindings\UrhoRendererBindings.doxyfile
..\JavaScript\BindingsGenerator\bin\release\BindingsGenerator.exe UrhoRendererBindings\UrhoRendererDocs\xml UrhoRendererBindings . AnimationController Camera EnvironmentLight Fog GraphicsWorld Light Mesh ParticleSystem Placeable Sky Terrain WaterPlane _float3 _float4 _Quat _float3x3 _float3x4 _float4x4 _Ray _Color _Point _Transform _Entity _IComponent _IAsset _IAssetStorage _IAssetTransfer _RayQueryResult
