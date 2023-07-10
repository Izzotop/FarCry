add_library(CryXml
    StdAfx.cpp
    StdAfx.h
    xml.cpp
    xml.h
)
target_link_libraries(CryXml PRIVATE CryCommon expat)
