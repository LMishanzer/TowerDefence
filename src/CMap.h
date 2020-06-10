#include "CEnemy.h"
#include <string>
#ifndef TOWERDEFENCE_MAP_H
#define TOWERDEFENCE_MAP_H

using namespace std;

class CMap {
public:
    int m_Width;
    int m_Height;
    char ** m_Field;

    int m_StartX;
    int m_StartY;
    int m_FinishX;
    int m_FinishY;

    int m_MaxEnemiesCount;
    int m_EnemyCount = 0;
    CEnemy ** m_Enemies;

    bool LoadMap(const string& path);
    void CompileEnemies() const;
    void AddEnemy(CEnemy &enemy);
    void Print() const;

    ~CMap();
};


#endif //TOWERDEFENCE_MAP_H
