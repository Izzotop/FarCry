add_library(CryFont SHARED
    CryFont.cpp
    CryFont.h
    CryPakIO.cpp
    CryPakIO.h
    FBitmap.cpp
    FBitmap.h
    FFont.cpp
    FFont.h
    FFontXML.cpp
    FontRenderer.cpp
    FontRenderer.h
    FontTexture.cpp
    FontTexture.h
    GlyphBitmap.cpp
    GlyphBitmap.h
    GlyphCache.cpp
    GlyphCache.h
    ICryFont.cpp
    StdAfx.cpp
    StdAfx.h
)
target_link_libraries(CryFont CryCommon freetype)
