add_subdirectory(PunkBuster)

add_library(CryNetwork SHARED
    CCPEndpoint.cpp
    CCPEndpoint.h
    Client.cpp
    Client.h
    ClientLocal.cpp
    ClientLocal.h
    ClientStateMachine.cpp
    ClientStateMachine.h
    CNP.h
    CommonDefines.h
    CompressionHelper.cpp
    CompressionHelper.h
    CryNetwork.cpp
    CTPEndpoint.cpp
    CTPEndpoint.h
    CTPEndpointGNB.cpp
    CTPEndpointGNB.h
    DatagramSocket.cpp
    DatagramSocket.h
    DefenceWall.cpp
    DefenceWall.h
    Interfaces.h
    NETServerSnooper.cpp
    NETServerSnooper.h
    Network.cpp
    Network.h
    NewUbisoftCDKey.cpp
    NewUbisoftClient.cpp
    NewUbisoftClient.h
    NewUbisoftMSClient.cpp
    NewUbisoftRegServer.cpp
    PingCalculator.h
    PunkBusterInterface.cpp
    PunkBusterInterface.h
    RConSystem.cpp
    RConSystem.h
    ScriptObjectNewUbisoftClient.cpp
    ScriptObjectNewUbisoftClient.h
    Server.cpp
    Server.h
    ServerSlot.cpp
    ServerSlot.h
    ServerSnooper.cpp
    ServerSnooper.h
    ServerStateMachine.cpp
    ServerStateMachine.h
    StateMachine.h
    StaticCharCompressor.cpp
    StaticCharCompressor.h
    StdAfx.cpp
    StdAfx.h
    UbisoftMemory.cpp
    UbisoftMemory.h
)
target_link_libraries(CryNetwork PRIVATE CryCommon PunkBuster)
target_compile_definitions(CryNetwork PRIVATE CRYNETWORK_EXPORTS
    NOT_USE_UBICOM_SDK # todo (Izzotop): Remove
)
