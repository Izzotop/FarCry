add_subdirectory(LUA)

add_library(CryScriptSystem SHARED
    StackGuard.h
    LuaCryPakIO.cpp
    FunctionHandler.h
    MemStats.cpp
    ScriptBuffer.cpp
    LuaCryPakIO.h
    StdAfx.cpp
    RecycleAllocator.h
    ScriptObject.cpp
    FunctionHandler.cpp
    ScriptSystem.cpp
    RecycleAllocator.cpp
    ScriptSystem.h
    StdAfx.h
    ScriptObject.h
    vectorlib.c
    CryScriptSystem.cpp
)
target_link_libraries(CryScriptSystem PRIVATE CryCommon lua41)
target_compile_definitions(CryScriptSystem PRIVATE CRYSCRIPTSYSTEM_EXPORTS)
