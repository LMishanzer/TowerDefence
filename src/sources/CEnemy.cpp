#include "../headers/CEnemy.h"
#include <iostream>

using namespace std;

CEnemy::CEnemy(char mark, int hp) {
    m_Mark = mark;
    m_MaxHealth = hp;
    m_CurrentHealth = m_MaxHealth;
    m_Iteration = 0;
}

CCoords CEnemy::GetPosition() const {
    return m_Pos;
}

void CEnemy::SetPosition(CCoords pos) {
    m_Pos = pos;
}

char CEnemy::GetMark() const {
    return m_Mark;
}

void CEnemy::Hit(int damage) {
    m_CurrentHealth -= damage;
}

bool CEnemy::IsDead() const {
    return m_CurrentHealth <= 0;
}
