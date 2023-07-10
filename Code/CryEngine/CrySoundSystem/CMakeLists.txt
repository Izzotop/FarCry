# CrySound by Firelight Technologies
add_library(crysound STATIC IMPORTED)
set_target_properties(crysound PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/crysound.lib)
set(libs
    crysound.lib   crysound64.lib
    crysoundvc.lib crysound64d.lib
)

add_library(CrySoundSystem SHARED
    ADPCMDecoder.cpp
    ADPCMDecoder.h
    CrySoundSystem.cpp
    DummyMusic.h
    DummySound.h
    MusicLoadSink.h
    MusicPattern.cpp
    MusicPattern.h
    MusicPatternInstance.cpp
    MusicPatternInstance.h
    MusicSystem.cpp
    MusicSystem.h
    OGGDecoder.cpp
    OGGDecoder.h
    PatternDecoder.h
    PCMDecoder.cpp
    PCMDecoder.h
    RandGen.cpp
    RandGen.h
    Sound.cpp
    Sound.h
    SoundBuffer.cpp
    SoundBuffer.h
    SoundSystem.cpp
    SoundSystem.h
    SoundSystemCommon.cpp
    SoundSystemCommon.h
    StdAfx.cpp
    StdAfx.h
)
target_link_libraries(CrySoundSystem PRIVATE CryCommon crysound ogg vorbisfile)
target_compile_definitions(CrySoundSystem PRIVATE CRYSOUNDSYSTEM_EXPORTS)
