add_library(CryInput SHARED
    CryInput.cpp
    Input.cpp
    Input.h
    Joystick.cpp
    Joystick.h
    Keyboard.h
    StdAfx.cpp
    StdAfx.h
    XActionMap.cpp
    XActionMap.h
    XActionMapManager.cpp
    XActionMapManager.h
    XDebugKeyboard.cpp
    XDebugKeyboard.h
# todo:   XGamepad.cpp
#    XGamepad.h
    XKeyboard.cpp
    XKeyboard.h
    XMouse.cpp
    XMouse.h
)
target_link_libraries(CryInput PUBLIC CryCommon)
target_include_directories(CryInput PRIVATE ${DirectX9_INCLUDE_DIR})
