add_library(PunkBuster
    pbcl.cpp
    pbcl.h
    pbcommon.h
    pbmd5.cpp
    pbmd5.h
    pbsdk.cpp
    pbsdk.h
    pbsv.cpp
    pbsv.h
)
target_link_libraries(PunkBuster PRIVATE CryCommon)
