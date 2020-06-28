#include "CCoords.h"
#include "CMovingObject.h"
#include "CEnemy.h"

#ifndef TOWERDEFENCE_CBULLET_H
#define TOWERDEFENCE_CBULLET_H

// class for keeping info about bullets
class CBullet : public CMovingObject {
public:
    /**
     * create a bullet with it's own way and damage
     * @param way : way of the bullet
     * @param length : length of the way
     * @param damage : damage of the bullet
     */
    explicit CBullet(CCoords * way, int length, int damage);

    int Damage() const;                 // returns damage value
    ~CBullet() override;

private:
    int m_Damage;
};


#endif //TOWERDEFENCE_CBULLET_H
