add_executable(FarCry WIN32
    resource.h
    Main.cpp
)
target_link_libraries(FarCry PRIVATE
    Cry3DEngine
    CryAISystem
    CryAnimation
    CryCommon
    CryEntitySystem
    CryFont
    CryGame
    CryInput
    CryMovie
    CryNetwork
    CryPhysics
    CryScriptSystem
    CrySoundSystem
    CrySystem
    CryXml
#    RenderDll
#    ResourceCompilerPC
)
