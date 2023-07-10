cmake_minimum_required(VERSION 3.25)
project(Far_Cry LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

add_compile_definitions(_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS) # todo (Izzotop): remove

set(BUILD_TESTING OFF)

set(CRY_SOURCE_DIR "c:\\Games\\Far Cry\\Bin32\\")
function(setup_cry_target_shared target)
    set_target_properties(${target} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CRY_SOURCE_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CRY_SOURCE_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CRY_SOURCE_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CRY_SOURCE_DIR}"
    )
endfunction()

add_subdirectory(Code/Libs)
add_subdirectory(Code/CryEngine)
