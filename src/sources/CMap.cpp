#include "../headers/CMap.h"
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <unistd.h>

using namespace std;

CMap::CMap() {
    m_Width = 0;
    m_Height = 0;
    m_Field = nullptr;

    m_MaxEnemiesCount = 0;
    m_EnemyCount = 0;
    m_MaxTowersCount = 0;
    m_TowersCount = 0;
    m_Enemies = nullptr;
    m_Towers = nullptr;
    m_Way = nullptr;
    m_PassedEnemies = 0;
    m_KilledEnemies = 0;
}

void CMap::Print() const {
    move(0,0);
    for (int i = 0; i < m_Height; i++) {
        for (int j = 0; j < m_Width; j++){
            printw("%c", m_Field[i][j]);
        }
        printw("\n");
    }
    printw("Passed enemies: %d\n", m_PassedEnemies);
    printw("Killed enemies: %d\n", m_KilledEnemies);
    refresh();
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
    file >> m_MaxTowersCount;
    file.get();

    m_Towers = new CTower*[m_MaxTowersCount];
    for (int i = 0; i < m_MaxTowersCount; i++){
        m_Towers[i] = nullptr;
    }

    m_Enemies = new CEnemy*[m_MaxEnemiesCount];
    for (int i = 0; i < m_MaxEnemiesCount; i++){
        m_Enemies[i] = nullptr;
    }

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

void CMap::Render() const {
    for (int i = 0; i < m_Height; i++){
        for (int j = 0; j < m_Width; j++){
            if (m_Field[i][j] != '#' && !(m_Field[i][j] >= '1' && m_Field[i][j] <= '9')
            && !(m_Field[i][j] >= 'A' && m_Field[i][j] <= 'Z') && m_Field[i][j] != '>'
            && m_Field[i][j] != '<' && m_Field[i][j] != '^' && m_Field[i][j] != '|'){
                m_Field[i][j] = ' ';
            }
        }
    }

    for (int i = 0; i < m_MaxEnemiesCount; i++) {
        if (m_Enemies[i])
            m_Field[m_Enemies[i]->GetPosition().y][m_Enemies[i]->GetPosition().x] = m_Enemies[i]->GetMark();
    }

    for (int i = 0; i < m_TowersCount; i++) {
        m_Field[m_Towers[i]->GetPosition().y][m_Towers[i]->GetPosition().x] = m_Towers[i]->GetMark();
        m_Towers[i]->IncrementIterator();
    }
}

void CMap::AddEnemy(CEnemy *enemy) {
    if (m_EnemyCount == m_MaxEnemiesCount || enemy == nullptr)
        return;
    m_Enemies[m_EnemyCount] = enemy;
    enemy->SetPosition(m_Start);
    m_EnemyCount++;
    if (m_EnemyCount == m_MaxEnemiesCount)
        m_EnemyCount = 0;
}

void CMap::MoveEnemies() {
    for (int i = 0; i < m_TowersCount; i++){
        for (int j = 0; j < m_MaxEnemiesCount; j++){
            if (m_Enemies[j]){
                if (abs(m_Towers[i]->GetPosition().y - m_Enemies[j]->GetPosition().y) <= m_Towers[i]->GetRange()
                && abs(m_Towers[i]->GetPosition().x - m_Enemies[j]->GetPosition().x) <= m_Towers[i]->GetRange()){
                    m_Enemies[j]->Hit(m_Towers[i]->GetDamage());
                    if (m_Enemies[j]->IsDead()){
                        delete m_Enemies[j];
                        m_Enemies[j] = nullptr;
                        m_KilledEnemies++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < m_MaxEnemiesCount; i++) {
        if (m_Enemies[i]) {
            if (m_Enemies[i]->GetPosition() == m_Finish) {
                delete m_Enemies[i];
                m_Enemies[i] = nullptr;
                m_PassedEnemies++;
            }
            else {
                m_Enemies[i]->IncrementIterator();
                m_Enemies[i]->SetPosition(m_Way[m_Enemies[i]->GetIteration()]);
            }
        }
    }
}

CMap::~CMap() {
    for (int i = 0; i < m_Height; i++)
    {
        delete [] m_Field[i];
    }
    delete [] m_Field;

    for (int i = 0; i < m_MaxEnemiesCount; i++)
        if (m_Enemies[i]){
            delete m_Enemies[i];
        }

    for (int i = 0; i < m_MaxTowersCount; i++)
        if (m_Towers[i])
            delete m_Towers[i];

    delete [] m_Towers;
    delete [] m_Enemies;
    delete [] m_Way;
}

bool CMap::IsOver() const {
    return m_PassedEnemies == 7;
}

void CMap::SetWay(CCoords *way) {
    m_Way = way;
}

bool CMap::AddTower(CTower *tower, int number) {
    if (m_TowersCount != m_MaxTowersCount && number >= 0 && number <= m_MaxTowersCount){
        CCoords temp = {0, 0};

        for (int i = 0; i < m_Height; i++){
            for (int j = 0; j < m_Width; j++) {
                if (m_Field[i][j] - 48 == number){
                    temp = {i, j};
                    break;
                }
            }
        }

        tower->SetPosition(temp);
        m_Towers[m_TowersCount] = tower;
        m_TowersCount++;
        return true;
    }
    return false;
}

int CMap::GetWidth() const {
    return m_Width;
}

int CMap::GetHeight() const {
    return m_Height;
}

CCoords CMap::GetStart() const {
    return m_Start;
}

CCoords CMap::GetFinish() const {
    return m_Finish;
}

char ** CMap::GetField() const {
    return m_Field;
}
