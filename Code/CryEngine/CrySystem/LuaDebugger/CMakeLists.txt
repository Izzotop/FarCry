add_library(LuaDebugger INTERFACE
    _TinyBrowseFolder.h
    _TinyCaptionWindow.h
    _TinyCoolEdit.h
    _TinyFileEnum.h
    _TinyImageList.h
    _TinyMain.h
    _TinyRegistry.h
    _TinySplitter.h
    _TinyStatusBar.h
    _TinyTreeList.h
    _TinyWindow.h
    AboutWnd.h
    FileTree.cpp
    FileTree.h
    LUADBG.cpp
    LUADBG.h
    LuaDbgInterface.cpp
    LuaDbgInterface.h
)
target_link_libraries(LuaDebugger INTERFACE CryCommon)
