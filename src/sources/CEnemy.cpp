#include "../headers/CEnemy.h"
#include <iostream>

using namespace std;

CEnemy::CEnemy(char mark, int hp) : CGameObject(){
    m_Mark = mark;
    m_MaxHealth = hp;
    m_CurrentHealth = m_MaxHealth;
}

void CEnemy::Hit(int damage) {
    m_CurrentHealth -= damage;
}

bool CEnemy::IsDead() const {
    return m_CurrentHealth <= 0;
}

int CEnemy::GetIteration() const {
    return m_Iteration;
}
