set(ZLIB_COMPAT ON)
set(ZLIB_ENABLE_TESTS OFF)
set(WITH_GTEST OFF)
add_subdirectory(zlib-ng)

set(FT_DISABLE_PNG TRUE)
set(FT_DISABLE_BZIP2 TRUE)
set(FT_DISABLE_BROTLI TRUE)
set(FT_DISABLE_HARFBUZZ TRUE)
add_subdirectory(freetype)

set(EXPAT_BUILD_TOOLS OFF)
set(EXPAT_BUILD_EXAMPLES OFF)
set(EXPAT_BUILD_TESTS OFF)
add_subdirectory(libexpat/expat)

add_subdirectory(ogg)
add_subdirectory(vorbis)

# add_subdirectory(curl) curl-7.12.2

add_subdirectory(Legacy/ASEQuerySDK)
add_subdirectory(Legacy/BinkSDK)
add_subdirectory(Legacy/DivxMedia)
add_subdirectory(Legacy/dx9_sdk)
add_subdirectory(Legacy/jpeg6)
add_subdirectory(Legacy/NvCg)
add_subdirectory(Legacy/NvParse)
add_subdirectory(Legacy/NvTriStrip)
# add_subdirectory(Ubisoft.com)
add_subdirectory(Legacy/Xtreme_Toolkit) # https://codejock.com/products/toolkitpro/
