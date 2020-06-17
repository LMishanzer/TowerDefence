#include "CCoords.h"
#include "CGameObject.h"
#include "CEnemy.h"

#ifndef TOWERDEFENCE_CBULLET_H
#define TOWERDEFENCE_CBULLET_H


class CBullet : public CGameObject {
public:
    explicit CBullet(CCoords * way, int length, int damage);
    bool IsEnd() const;
    int Damage() const;
    void IncrementIterator() override;
    ~CBullet();

private:
    int m_Damage;
    CCoords m_Target{};
    CCoords * m_Way;
    int m_WayLength;
};


#endif //TOWERDEFENCE_CBULLET_H
