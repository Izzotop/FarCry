add_library(RenderCommonStd
    CrtOverrides.h
    RenderPCH.cpp
    RenderPCH.h
    stdafx.cpp
    stdafx.h
)
target_link_libraries(RenderCommonStd PUBLIC CryCommon)

add_subdirectory(Common)
add_subdirectory(XRenderD3D8)
add_subdirectory(XRenderD3D9)
add_subdirectory(XRenderNULL)
add_subdirectory(XRenderOGL)
add_subdirectory(XRenderPS2)
