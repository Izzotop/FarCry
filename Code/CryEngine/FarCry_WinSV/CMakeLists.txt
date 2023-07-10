add_executable(FarCry_WinSV
    BasicConsole.cpp
    BasicConsole.h

    DedicatedServer.cpp
    DedicatedServer.h

    FarCry_WinSV.cpp

    resource.h

    stdafx.cpp
    stdafx.h

    WinAndConsole.cpp
)
target_link_libraries(FarCry_WinSV PRIVATE CryCommon)
