#include "CCoords.h"
#include "CGameObject.h"

#ifndef TOWERDEFENCE_CENEMY_H
#define TOWERDEFENCE_CENEMY_H

enum KIND{TERRESTRIAL, AIR};

class CEnemy : public CGameObject {
public:
    CEnemy(char mark, int hp);
    void Hit(int damage);
    bool IsDead() const;
    int GetIteration() const;

private:
    int m_MaxHealth;
    int m_CurrentHealth;
};


#endif //TOWERDEFENCE_CENEMY_H
