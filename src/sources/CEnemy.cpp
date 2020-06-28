#include "../headers/CEnemy.h"

CEnemy::CEnemy(char mark, int hp, int gold, int diamonds, CCoords * way, int length) : CMovingObject(way, length){
    m_Mark = mark;
    m_MaxHealth = hp;
    m_CurrentHealth = m_MaxHealth;
    m_PriceGold = gold;
    m_PriceDiamonds = diamonds;
}

void CEnemy::Hit(int damage) {
    m_CurrentHealth -= damage;
}

bool CEnemy::IsDead() const {
    return m_CurrentHealth <= 0;
}

int CEnemy::GetPriceGold() const {
    return m_PriceGold;
}

int CEnemy::GetPriceDiamonds() const {
    return m_PriceDiamonds;
}
