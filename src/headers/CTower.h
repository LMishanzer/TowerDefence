#include "CCoords.h"
#include "CBullet.h"
#include "CGameObject.h"

#ifndef TOWERDEFENCE_CTOWER_H
#define TOWERDEFENCE_CTOWER_H


class CTower : public CGameObject {
public:
    CTower(char mark);
    char GetMark() const;
    int GetRange() const;
    int GetDamage() const;
    bool IsShoot() const;
    CBullet * Shoot() const;

private:
    int m_Damage;
    int m_Range;
    int m_FireRate;
    char m_Mark;

};


#endif //TOWERDEFENCE_CTOWER_H
