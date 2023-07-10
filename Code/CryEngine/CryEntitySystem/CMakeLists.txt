add_library(CryEntitySystem SHARED
    EntitySystem.cpp
    CryEntityDLL.cpp
    EntityIt.cpp
    EntityCamera.cpp
    stdafx.cpp
    IDGenerator.h
    LipSync.cpp
    LipSync.h
    EntityPesistence.cpp
    RandomExprLoadSink.h
    EntityCreation.cpp
    EntityIt.h
    RandomExprLoadSink.cpp
    EntityCamera.h
    EntityRender.cpp
    stdafx.h
    Entity.cpp
    Entity.h
    EntitySystem.h
    IDGenerator.cpp
    )
target_link_libraries(CryEntitySystem PRIVATE CryCommon)
target_compile_definitions(CryEntitySystem PRIVATE CRYENTITYDLL_EXPORTS)
