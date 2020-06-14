#include "CEnemy.h"
#include "CTower.h"
#include <string>
#ifndef TOWERDEFENCE_MAP_H
#define TOWERDEFENCE_MAP_H

using namespace std;

class CMap {
public:
    CMap();
    void MoveEnemies();
    bool LoadMap(const string& path);
    void CompileEnemies() const;
    void AddEnemy(CEnemy * enemy);
    bool AddTower(CTower * tower, int number);
    void Print() const;
    bool IsOver() const;
    void SetWay(CCoords * way, int length);
    ~CMap();

    int m_Width;
    int m_Height;
    char ** m_Field;

    CCoords m_Start{};
    CCoords m_Finish{};

    int m_MaxEnemiesCount;
    int m_EnemyCount;
    int m_MaxTowersCount;
    int m_TowersCount;
    CEnemy ** m_Enemies;
    CTower ** m_Towers;
    CCoords * m_Way;
    int m_WayLength;
    int m_PassedEnemies;
    int m_KilledEnemies;
};


#endif //TOWERDEFENCE_MAP_H
