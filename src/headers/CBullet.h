#include "CCoords.h"
#include "CGameObject.h"

#ifndef TOWERDEFENCE_CBULLET_H
#define TOWERDEFENCE_CBULLET_H


class CBullet : public CGameObject {
public:
    explicit CBullet(int damage);

private:
    int m_Damage;
};


#endif //TOWERDEFENCE_CBULLET_H
