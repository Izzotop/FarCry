add_library(ResourceCompiler
    CfgFile.cpp
    CfgFile.h
    CgfUtils.cpp
    CgfUtils.h
    ChunkFileReader.cpp
    ChunkFileReader.h
    CmdLine.cpp
    CmdLine.h
    Config.cpp
    Config.h
    ConvertContext.h
    CryBoneDesc.cpp
    CryBoneDesc.h
    CryBoneHierarchyLoader.cpp
    CryBoneHierarchyLoader.h
    CryChunkedFile.cpp
    CryChunkedFile.h
    CryVertexBinding.cpp
    CryVertexBinding.h
    DebugLog.h
    ExtensionManager.cpp
    ExtensionManager.h
    FileMapping.cpp
    FileMapping.h
    FileUtil.cpp
    FileUtil.h
    ICfgFile.h
    IConfig.h
    IConvertor.h
    IRCLog.h
    IResCompiler.h
    MathUtils.h
    PathUtil.h
    PortableString.h
    QuaternionExponentX87.h
    ResComDefs.h
    ResourceCompiler.cpp
    ResourceCompiler.h

    CrtOverrides.h
    RenderPCH.cpp
    RenderPCH.h

    stdafx.cpp
    stdafx.h
)
target_link_libraries(ResourceCompiler PRIVATE CryCommon)
target_include_directories(ResourceCompiler PUBLIC .)
