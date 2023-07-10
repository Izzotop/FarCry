add_subdirectory(LuaDebugger)

add_library(CrySystem SHARED
    LuaDebugger/_TinyBrowseFolder.h
    LuaDebugger/_TinyCaptionWindow.h
    LuaDebugger/_TinyCoolEdit.h
    LuaDebugger/_TinyFileEnum.h
    LuaDebugger/_TinyImageList.h
    LuaDebugger/_TinyMain.h
    LuaDebugger/_TinyRegistry.h
    LuaDebugger/_TinySplitter.h
    LuaDebugger/_TinyStatusBar.h
    LuaDebugger/_TinyTreeList.h
    LuaDebugger/_TinyWindow.h
    LuaDebugger/AboutWnd.h
    LuaDebugger/FileTree.cpp
    LuaDebugger/FileTree.h
    LuaDebugger/LUADBG.cpp
    LuaDebugger/LUADBG.h
    LuaDebugger/LuaDbgInterface.cpp
    LuaDebugger/LuaDbgInterface.h

    XML/_XMLDOMParserImpl.cpp
    XML/_XMLDOMParserImpl.h

    XML/nanoxml.h
    XML/xml.cpp
    XML/xml.h
    XML/xml_string.h

    XML/XMLDOMDocumentImpl.cpp
    XML/XMLDOMDocumentImpl.h
    XML/XMLDOMNodeImpl.cpp
    XML/XMLDOMNodeImpl.h
    XML/XMLDOMNodeListImpl.cpp
    XML/XMLDOMNodeListImpl.h

    ApplicationHelper.cpp
    ApplicationHelper.h
    CompressedFile.cpp
    CPUDetect.cpp
    CPUDetect.h
    CritSection.h

    CryMemoryManager.cpp
    CryPak.cpp
    CryPak.h
    CrySizerImpl.cpp
    CrySizerImpl.h
    CrySizerStats.cpp
    CrySizerStats.h

    CrySystem.aps
    CrySystem.rc

    CryWaterMark.h
    DataProbe.cpp
    DataProbe.h
    DebugCallStack.cpp
    DebugCallStack.h
    DllMain.cpp
    DownloadManager.cpp
    DownloadManager.h
    DxDiag.h
    FrameProfileRender.cpp
    FrameProfileSystem.cpp
    FrameProfileSystem.h
    getdxver.cpp
    HTTPDownloader.cpp
    HTTPDownloader.h
    Log.cpp
    Log.h
    Mailer.cpp
    Mailer.h

    md5.c
    md5.h

    MTSafeAllocator.cpp
    MTSafeAllocator.h
    PakVars.h
    RandGen.cpp
    RandGen.h
    RefReadStream.cpp
    RefReadStream.h
    RefReadStreamProxy.cpp
    RefReadStreamProxy.h
    RefStreamEngine.cpp
    RefStreamEngine.h

    resource.h

    ScriptBinding.cpp
    ScriptObjectAnimation.cpp
    ScriptObjectAnimation.h
    ScriptObjectEntity.cpp
    ScriptObjectEntity.h
    ScriptObjectMovie.cpp
    ScriptObjectMovie.h
    ScriptObjectParticle.cpp
    ScriptObjectParticle.h
    ScriptObjectScript.cpp
    ScriptObjectScript.h
    ScriptObjectSound.cpp
    ScriptObjectSound.h
    ScriptObjectSystem.cpp
    ScriptObjectSystem.h
    ScriptSink.cpp
    ScriptSink.h

    SourceSafeHelper.cpp
    SourceSafeHelper.h

    SSAPI.DLL

    StdAfx.cpp
    StdAfx.h

    StreamEngine.cpp
    StreamEngine.h
    System.cpp
    System.h
    SystemCFG.cpp
    SystemCFG.h
    SystemInit.cpp
    SystemRender.cpp

    SystemWin32.cpp

    Timer.cpp
    Timer.h
    Validator.h

    XConsole.cpp
    XConsole.h
    XConsoleVariable.cpp
    XConsoleVariable.h

    ZipDir.h
    ZipDirCache.cpp
    ZipDirCache.h
    ZipDirCacheFactory.cpp
    ZipDirCacheFactory.h
    ZipDirCacheRW.cpp
    ZipDirCacheRW.h
    ZipDirFind.cpp
    ZipDirFind.h
    ZipDirFindRW.cpp
    ZipDirFindRW.h
    ZipDirList.cpp
    ZipDirList.h
    ZipDirStructures.cpp
    ZipDirStructures.h
    ZipDirTree.cpp
    ZipDirTree.h
    ZipFile.h
    ZipFileFormat.h
)
target_link_libraries(CrySystem PRIVATE CryCommon zlib expat)
target_include_directories(CrySystem PRIVATE .)
target_compile_definitions(CrySystem PRIVATE CRYSYSTEM_EXPORTS)
