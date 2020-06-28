#include "../headers/CMap.h"
#include <iostream>
#include <fstream>
#include <ncurses.h>

using namespace std;

CMap::CMap(string path, CWallet * wallet) {
    ifstream file;
    file.open(path);

    // get properties from the file
    file >> m_Height;
    file >> m_Width;
    file >> m_Start.y;
    file >> m_Start.x;
    file >> m_Finish.y;
    file >> m_Finish.x;
    file >> m_MaxEnemiesCount;
    file >> m_MaxTowersCount;
    file >> m_PassedEnemiesToOver;
    file.get();

    // creating array for towers
    m_Towers = new CTower*[m_MaxTowersCount];
    for (int i = 0; i < m_MaxTowersCount; i++){
        m_Towers[i] = nullptr;
    }

    // creating arrays for enemies and bullets;
    m_Enemies = new CEnemy*[m_MaxEnemiesCount];
    m_Bullets = new CBullet*[m_MaxEnemiesCount];
    for (int i = 0; i < m_MaxEnemiesCount; i++){
        m_Enemies[i] = nullptr;
        m_Bullets[i] = nullptr;
    }

    // generating field
    m_Field = new char*[m_Height];
    for (int i = 0; i < m_Height; i++) {
        m_Field[i] = new char[m_Width];
        string temp;
        getline(file, temp);
        for (int j = 0; j < m_Width; j++){
            m_Field[i][j] = temp[j];
        }
    }

    m_EnemyCount = 0;
    m_BulletCount = 0;
    m_TowersCount = 0;
    m_PassedEnemies = 0;
    m_KilledEnemies = 0;

    m_Wallet = wallet;
}

void CMap::Print() const {
    move(0,0);
    // print field
    for (int i = 0; i < m_Height; i++) {
        for (int j = 0; j < m_Width; j++){
            printw("%c", m_Field[i][j]);
        }
        printw("\n");
    }
}

void CMap::Render() const {
    // show field
    for (int i = 0; i < m_Height; i++){
        for (int j = 0; j < m_Width; j++){
            if (m_Field[i][j] != '#' && !(m_Field[i][j] >= '1' && m_Field[i][j] <= '9')
            && !(m_Field[i][j] >= 'A' && m_Field[i][j] <= 'Z') && m_Field[i][j] != '>'
            && m_Field[i][j] != '<' && m_Field[i][j] != '^' && m_Field[i][j] != '|'){
                m_Field[i][j] = ' ';
            }
        }
    }

    // show enemies and bullets
    for (int i = 0; i < m_MaxEnemiesCount; i++) {
        if (m_Enemies[i])
            m_Field[m_Enemies[i]->GetPosition().y][m_Enemies[i]->GetPosition().x] = m_Enemies[i]->GetMark();
        if (m_Bullets[i] && (m_Field[m_Bullets[i]->GetPosition().y][m_Bullets[i]->GetPosition().x] < '0'
        || m_Field[m_Bullets[i]->GetPosition().y][m_Bullets[i]->GetPosition().x] > '9')){
            m_Field[m_Bullets[i]->GetPosition().y][m_Bullets[i]->GetPosition().x] = m_Bullets[i]->GetMark();
        }
    }

    // show towers
    for (int i = 0; i < m_TowersCount; i++) {
        m_Field[m_Towers[i]->GetPosition().y][m_Towers[i]->GetPosition().x] = m_Towers[i]->GetMark();
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

void CMap::Shoot() {
    for (int i = 0; i < m_TowersCount; i++){
        for (int j = 0; j < m_MaxEnemiesCount; j++){
            if (m_Enemies[j]){
                // checking if shoot needed
                if (abs(m_Towers[i]->GetPosition().y - m_Enemies[j]->GetPosition().y) <= m_Towers[i]->GetRange()
                && abs(m_Towers[i]->GetPosition().x - m_Enemies[j]->GetPosition().x) <= m_Towers[i]->GetRange()){
                    // shoot (new instance of CBullet)
                    m_Bullets[m_BulletCount] = m_Towers[i]->Shoot(m_Field, m_Width, m_Height,
                            m_Enemies[j]->GetPosition());
                    m_BulletCount++;

                    if (m_BulletCount == m_MaxEnemiesCount){
                        m_BulletCount = 0;
                    }
                    break;
                }
            }
        }
    }
}

void CMap::MoveEnemies() {
    for (int i = 0; i < m_MaxEnemiesCount; i++) {
        if (m_Enemies[i]) {
            // if enemy reach finish
            if (m_Enemies[i]->GetPosition() == m_Finish) {
                delete m_Enemies[i];
                m_Enemies[i] = nullptr;
                m_PassedEnemies++;
            }
            // move forward
            else {
                m_Enemies[i]->MoveToNext();
            }
        }
    }

    Shoot();        // checking if shoot is needed
}

void CMap::MoveBullets() {
    for (int i = 0; i < m_MaxEnemiesCount; i++) {
        if (m_Bullets[i]) {
            m_Bullets[i]->MoveToNext();

            if (m_Bullets[i]->IsEnd()){
                IsReached(i);

                delete m_Bullets[i];
                m_Bullets[i] = nullptr;
            }
        }
    }
}

void CMap::IsReached(int bulletNumber) {
    for (int j = 0; j < m_MaxEnemiesCount; j++){
        if (m_Enemies[j])
            // compare positions of every bullet and every enemy
            if (m_Enemies[j]->GetPosition() == m_Bullets[bulletNumber]->GetPosition()){
                m_Enemies[j]->Hit(m_Bullets[bulletNumber]->Damage());
                if (m_Enemies[j]->IsDead()){
                    // income to the wallet
                    m_Wallet->Income(m_Enemies[j]->GetPriceGold(),
                                     m_Enemies[j]->GetPriceDiamonds());
                    delete m_Enemies[j];
                    m_Enemies[j] = nullptr;
                    m_KilledEnemies++;
                }
                break;
            }
    }
}

CMap::~CMap() {
    for (int i = 0; i < m_Height; i++)
    {
        delete [] m_Field[i];
    }
    delete [] m_Field;

    for (int i = 0; i < m_MaxEnemiesCount; i++) {
        if (m_Enemies[i])
            delete m_Enemies[i];
        if (m_Bullets[i])
            delete m_Bullets[i];
    }

    for (int i = 0; i < m_MaxTowersCount; i++) {
        if (m_Towers[i])
            delete m_Towers[i];
    }

    delete [] m_Bullets;
    delete [] m_Towers;
    delete [] m_Enemies;
}

bool CMap::IsOver() const {
    return m_PassedEnemies == m_PassedEnemiesToOver;
}

bool CMap::AddTower(CTower *tower, int number) {
    if (m_TowersCount != m_MaxTowersCount && number >= 0 && number <= m_MaxTowersCount){
        CCoords temp = {0, 0};

        // searching tower position
        for (int i = 0; i < m_Height; i++){
            for (int j = 0; j < m_Width; j++) {
                if (m_Field[i][j] - 48 == number){
                    temp = {i, j};
                    break;
                }
            }
        }

        if (temp == CCoords{0, 0})
            return false;

        tower->SetPosition(temp);       // setting tower position
        m_Towers[m_TowersCount] = tower;
        // expanse from the wallet
        m_Wallet->Expanse(m_Towers[m_TowersCount]->GetPriceGold(),
                m_Towers[m_TowersCount]->GetPriceDiamonds());

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

int CMap::PassedEnemies() const {
    return m_PassedEnemies;
}

int CMap::KilledEnemies() const {
    return m_KilledEnemies;
}
