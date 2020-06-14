#include "CEnemy.h"
#include <iostream>

using namespace std;

CEnemy::CEnemy(char mark, int hp) {
    m_Mark = mark;
    m_MaxHealth = hp;
    m_CurrentHealth = m_MaxHealth;
    m_Iteration = 0;
}
