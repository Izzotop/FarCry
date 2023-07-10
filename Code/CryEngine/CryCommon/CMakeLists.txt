add_library(CryCommon INTERFACE
    _ScriptableEx.h
    _TinyWindow.h
    AABBSV.h
    AgentParams.h
    AnimKey.h
    ColorDefs.h
    CRE2DQuad.h
    CREDummy.h
    CREFlashBang.h
    CREGlare.h
    CREOcclusionQuery.h
    CREOcLeaf.h
    CREPolyMesh.h
    CREScreenProcess.h
    CREShadowMap.h
    CRESky.h
    CRETerrainSector.h
    CRETriMeshAdditionalShadow.h
    CRETriMeshShadow.h
    CrtDebugStats.h
    Cry_Camera.h
    Cry_Color4.h
    Cry_Geo.h
    Cry_GeoDistance.h
    Cry_GeoIntersect.h
    Cry_GeoOverlap.h
    Cry_Math.h
    Cry_Matrix.h
    Cry_Quat.h
    Cry_Vector2.h
    Cry_Vector3.h
    Cry_XOptimise.h
    CryAnimationScriptCommands.h
    CryCharAnimationParams.h
    CryCharFxTrailParams.h
    CryCharMorphParams.h
    CryCompiledFile.h
    CryEngineDecalInfo.h
    CryFile.h
    CryHeaders.h
    CryLibrary.h
    CryMemoryManager.h
    CryParticleSpawnInfo.h
    CryPhysics.h
    CrySizer.h

    crysound.h
    crysound64.h

    CryVersion.h
    EntityDesc.h

    Font.h

    FrameProfiler.h

    fSinCos64.lib

    I3DEngine.h
    I3DIndoorEngine.h
    IAgent.h
    IAISystem.h
    IBindable.h
    IBitStream.h
    ICompressionHelper.h
    IConsole.h
    ICryAnimation.h
    ICryPak.h
    IDataProbe.h
    IEdgeConnectivityBuilder.h
    IEntityRenderState.h
    IEntitySystem.h
    IFont.h
    IGame.h
    IInput.h
    ILipSync.h
    ILMSerializationManager.h
    ILog.h
    IMarkers.h
    IMiniLog.h
    IMovieSystem.h
    INetwork.h
    IPAddress.h
    IPhysics.h
    IProcess.h
    IRenderer.h
    IScriptSystem.h
    IShader.h
    ISound.h
    IStatObj.h
    IStreamEngine.h
    IStreamPersist.h
    ISystem.h
    ITimer.h
    IValidator.h
    IXGame.h
    IXml.h
    IXMLDOM.h
    LeafBuffer.h

    list2.h
    LMCompStructures.h
    MakMatInfoFromMAT_ENTITY.h
    matrixnm.h
    MeshIdx.h
    Names.h
    physinterface.h
    platform.h
    primitives.h
    ProjectDefines.h
    Range.h
    RendElement.h
    ScriptObjectVector.h
    SerializeBuffer.h
    smartptr.h
    StlDbgAlloc.h
    StlUtils.h
    Stream.h
    StreamData.h
    StringUtils.h
    TAlloc.h
    Tarray.h
    TArrays.h
    TimeValue.h
    TString.h
    VertexBufferSource.h
    VertexFormats.h

    Linux32Specific.h
    Linux64Specific.h
    LinuxSpecific.h

    Win32specific.h
    Win64specific.h

    XboxSpecific.h

    XmlParser.h
    XmlParserFont.h
    XmlStream.h
)
target_compile_definitions(CryCommon INTERFACE CRYFONT_EXPORTS)
target_include_directories(CryCommon INTERFACE .)
set_target_properties(CryCommon PROPERTIES LINKER_LANGUAGE CXX)
