#include "CMap.h"
#include <iostream>
#include <fstream>

using namespace std;

CMap::CMap() {
    m_Width = 0;
    m_Height = 0;
    m_Field = nullptr;

    m_MaxEnemiesCount = 0;
    m_EnemyCount = 0;
    m_Enemies = nullptr;
    m_Way = nullptr;
    m_WayLength = 0;
}

void CMap::Print() const {
    for (int i = 0; i < m_Height; i++) {
        for (int j = 0; j < m_Width; j++){
            cout << m_Field[i][j];
        }
        cout << endl;
    }
}

bool CMap::LoadMap(const string& path) {
    ifstream file;
    file.open(path);

    file >> m_Height;
    file >> m_Width;
    file >> m_Start.y;
    file >> m_Start.x;
    file >> m_Finish.y;
    file >> m_Finish.x;
    file >> m_MaxEnemiesCount;

    file.get();

    m_Enemies = new CEnemy*[m_MaxEnemiesCount];
    m_Field = new char*[m_Height];
    for (int i = 0; i < m_Height; i++) {
        m_Field[i] = new char[m_Width];
        string temp;
        getline(file, temp);
        for (int j = 0; j < m_Width; j++){
            m_Field[i][j] = temp[j];
        }
    }

    return true;
}

void CMap::CompileEnemies() const {
    for (int i = 0; i < m_EnemyCount; i++) {
        m_Field[m_Enemies[i]->m_Pos.y][m_Enemies[i]->m_Pos.x] = m_Enemies[i]->m_Mark;
    }
}

void CMap::AddEnemy(CEnemy &enemy) {
    if (m_EnemyCount == m_MaxEnemiesCount)
        return;
    m_Enemies[m_EnemyCount] = &enemy;
    enemy.m_Iteration = 0;
    enemy.m_Pos = m_Start;
    m_EnemyCount++;
}

void CMap::MoveEnemies() const {
    for (int i = 0; i < m_EnemyCount; i++){
        m_Enemies[i]->m_Iteration++;
        m_Enemies[i]->m_Pos = m_Way[m_Enemies[i]->m_Iteration];
    }
}

CMap::~CMap() {
    for (int i = 0; i < m_Height; i++)
    {
        delete [] m_Field[i];
    }
    delete [] m_Field;

//    for (CEnemy * i = *m_Enemies; i != nullptr; i++)
//        delete i;
    delete [] m_Enemies;
}
