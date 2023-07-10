add_library(CrySystemXml STATIC
    _XMLDOMParserImpl.cpp
    _XMLDOMParserImpl.h

    nanoxml.h
    xml.cpp
    xml.h
    xml_string.h

    XMLDOMDocumentImpl.cpp
    XMLDOMDocumentImpl.h
    XMLDOMNodeImpl.cpp
    XMLDOMNodeImpl.h
    XMLDOMNodeListImpl.cpp
    XMLDOMNodeListImpl.h
)
target_link_libraries(CrySystemXml PRIVATE CryCommon expat)
