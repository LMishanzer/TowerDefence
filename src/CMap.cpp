#include "CMap.h"
#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

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
    file >> m_StartY;
    file >> m_StartX;
    file >> m_FinishY;
    file >> m_FinishX;
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
        m_Field[m_Enemies[i]->m_PosY][m_Enemies[i]->m_PosX] = m_Enemies[i]->m_Mark;
    }
}

void CMap::AddEnemy(CEnemy &enemy) {
    if (m_EnemyCount == m_MaxEnemiesCount)
        return;
    m_Enemies[m_EnemyCount] = &enemy;
    m_EnemyCount++;
}

CMap::~CMap() {
    for (int i = 0; i < m_Height; i++)
    {
        delete [] m_Field[i];
    }
    delete [] m_Field;

    for (CEnemy * i = *m_Enemies; i != nullptr; i++)
        delete i;
    delete [] m_Enemies;
}
