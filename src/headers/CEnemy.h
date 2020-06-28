#include "CCoords.h"
#include "CMovingObject.h"

#ifndef TOWERDEFENCE_CENEMY_H
#define TOWERDEFENCE_CENEMY_H


class CEnemy : public CMovingObject {
public:
    CEnemy(char mark, int hp, int gold, int diamonds, CCoords * way, int length);
    void Hit(int damage);       // get hit from a bullet
    bool IsDead() const;        // if health <= 0
    int GetPriceGold() const;
    int GetPriceDiamonds() const;
    virtual ~CEnemy() = default;

private:
    int m_MaxHealth;
    int m_CurrentHealth;
    int m_PriceGold;
    int m_PriceDiamonds;
};


#endif //TOWERDEFENCE_CENEMY_H
