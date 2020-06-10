#include "CEnemy.h"
//#include "CRoute.h"
#include <string>
#ifndef TOWERDEFENCE_MAP_H
#define TOWERDEFENCE_MAP_H

using namespace std;

class CMap {
public:
    int m_Width;
    int m_Height;
    char ** m_Field;

    CCoords m_Start{};
    CCoords m_Finish{};

    int m_MaxEnemiesCount;
    int m_EnemyCount;
    CEnemy ** m_Enemies;
    CCoords * m_Way;
    int m_WayLength;

    CMap();
    void MoveEnemies() const;
    bool LoadMap(const string& path);
    void CompileEnemies() const;
    void AddEnemy(CEnemy &enemy);
    void Print() const;

    ~CMap();
};


#endif //TOWERDEFENCE_MAP_H
