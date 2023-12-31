add_library(CryAnimation SHARED
    AnimationLayerInfo.h
    AnimObject.cpp
    AnimObject.h
    AnimObjectLoader.cpp
    AnimObjectLoader.h
    AnimObjectManager.cpp
    AnimObjectManager.h
    BoneLightBindInfo.cpp
    BoneLightBindInfo.h
    BoneLightDynamicBind.cpp
    BoneLightDynamicBind.h
    BSplineKnots.cpp
    BSplineKnots.h
    BSplineOpen.cpp
    BSplineOpen.h
    BSplineVec3dPacked.cpp
    BSplineVec3dPacked.h
    CgfUtils.cpp
    CgfUtils.h
    ChunkFileReader.cpp
    ChunkFileReader.h
    Controller.cpp
    Controller.h
    ControllerCryBone.cpp
    ControllerCryBone.h
    ControllerManager.cpp
    ControllerManager.h
    ControllerPackedBSpline.cpp
    ControllerPackedBSpline.h
    ControllerTCB.cpp
    ControllerTCB.h
    CryAnimationBase.cpp
    CryAnimationBase.h
    CryAnimationInfo.h
    CryBone.cpp
    CryBone.h
    CryBoneDesc.cpp
    CryBoneDesc.h
    CryBoneHierarchyLoader.cpp
    CryBoneHierarchyLoader.h
    CryBoneInfo.cpp
    CryBoneInfo.h
    CryCharBody.cpp
    CryCharBody.h
    CryCharDecal.cpp
    CryCharDecal.h
    CryCharDecalBuilder.cpp
    CryCharDecalBuilder.h
    CryCharDecalCommon.h
    CryCharDecalManager.cpp
    CryCharDecalManager.h
    CryCharFxTrail.cpp
    CryCharFxTrail.h
    CryCharInstance.cpp
    CryCharInstance.h
    CryCharInstanceRenderParams.cpp
    CryCharInstanceRenderParams.h
    CryCharManager.cpp
    CryCharManager.h
    CryCharParticleManager.cpp
    CryCharParticleManager.h
    CryCharRenderElement.cpp
    CryCharRenderElement.h
    CryCharReShadowManager.cpp
    CryCharReShadowManager.h
    CryCharReShadowVolume.cpp
    CryCharReShadowVolume.h
    CryGeometryInfo.cpp
    CryGeometryInfo.h
    CryGeomMorphTarget.cpp
    CryGeomMorphTarget.h
    CryKeyInterpolation.cpp
    CryKeyInterpolation.h
    CryModEffAnimation.cpp
    CryModEffAnimation.h
    CryModEffector.h
    CryModEffIKSolver.cpp
    CryModEffIKSolver.h
    CryModEffMorph.cpp
    CryModEffMorph.h
    CryModel.cpp
    CryModel.h
    CryModel-Data.cpp
    CryModelAnimationContainer.cpp
    CryModelAnimationContainer.h
    CryModelArrays.cpp
    CryModelGeometryLoader.cpp
    CryModelGeometryLoader.h
    CryModelLoader.cpp
    CryModelLoader.h
    CryModelShadowVolume.cpp
    CryModelState.cpp
    CryModelState.h
    CryModelStatePhys.cpp
    CryModelSubmesh.cpp
    CryModelSubmesh.h
    CrySkinAMD64.asm
    CrySkinBase.cpp
    CrySkinBase.h
    CrySkinBasisBuilder.cpp
    CrySkinBasisBuilder.h
    CrySkinBuilder.cpp
    CrySkinBuilder.h
    CrySkinBuilderBase.cpp
    CrySkinBuilderBase.h
    CrySkinFull.cpp
    CrySkinFull.h
    CrySkinMorph.cpp
    CrySkinMorph.h
    CrySkinMorphBuilder.cpp
    CrySkinMorphBuilder.h
    CrySkinRigidBasis.cpp
    CrySkinRigidBasis.h
    CrySkinTypes.h
    CryVertexBinding.cpp
    CryVertexBinding.h
    cvars.cpp
    cvars.h
    cvars-list.h
    DebugUtils.cpp
    DebugUtils.h
    drand.cpp
    drand.h
    FileMapping.cpp
    FileMapping.h
    GeomCommon.h
    IncContHeap.cpp
    IncContHeap.h
    makepath.c
    makepath.cpp
    makepath.h
    MathUtils.cpp
    MathUtils.h

#    QuaternionExponentX87.c
    QuaternionExponentX87.cpp
    QuaternionExponentX87.h

    RenderUtils.cpp
    RenderUtils.h
    SimpleFrameProfiler.cpp
    SimpleFrameProfiler.h
    SparseArrayDriver.h
    splitpath.c
    splitpath.cpp
    splitpath.h
    SSEUtils.cpp
    SSEUtils.h
    stdafx.cpp
    stdafx.h
    TCBSpline.h
    TFace.h
    Vec3a16.h
    VertexBufferArrayDrivers.cpp
    VertexBufferArrayDrivers.h
    XBoxExport.cpp
)
target_link_libraries(CryAnimation PRIVATE CryCommon)
target_compile_definitions(CryAnimation PRIVATE CRYANIMATION_EXPORTS) # COMP_VC DO_ASM OS_WIN32 PROC_INTEL
