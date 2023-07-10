#pragma once
#include <vector>

typedef std::vector<bool> VectorBools;

class CBuildingIDManager {

    VectorBools m_vAvailable;

public:
    CBuildingIDManager();
    ~CBuildingIDManager();
    int GetId();
    void FreeId(int nID);
    void FreeAll();
};
