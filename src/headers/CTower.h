#include "CCoords.h"
#include "CBullet.h"
#include "CGameObject.h"

#ifndef TOWERDEFENCE_CTOWER_H
#define TOWERDEFENCE_CTOWER_H


// class for towers
class CTower : public CGameObject {
public:
    explicit CTower(char mark);                                             // creates a tower of an certain type
    int GetRange() const;                                                   // return range of tower fire
    int GetPriceGold() const;                                               // returns price (gold)
    int GetPriceDiamonds() const;                                           // returns price (diamonds)
    CBullet * Shoot(char ** field, int width, int height, CCoords target);  // generating a shoot
    ~CTower() = default;

private:
    int m_Damage;
    int m_Range;
    int m_FireRate;
    int m_PriceGold;
    int m_PriceDiamonds;
};


#endif //TOWERDEFENCE_CTOWER_H
