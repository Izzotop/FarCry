add_library(ResourceCompilerImage
    resource.h

    dds.h
    ImageCompiler.cpp
    ImageCompiler.h
    ImageExports.def
    ImageObject.cpp
    ImageObject.h
    neuquant.cpp
    neuquant.h
    Properties.h
    RelativeMouseInput.cpp
    RelativeMouseInput.h
    ResourceCompilerImage.cpp
    ResourceCompilerImage.h
    ResourceCompilerImage.rc
    stdafx.cpp
    stdafx.h
    UserDialog.cpp
    UserDialog.h
)
target_link_libraries(ResourceCompilerImage PRIVATE CryCommon ResourceCompiler d3d9)
target_compile_definitions(ResourceCompilerImage PRIVATE RESOURCECOMPILERIMAGE_EXPORTS)
