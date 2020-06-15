#include "CCoords.h"
#include "CGameObject.h"

#ifndef TOWERDEFENCE_CENEMY_H
#define TOWERDEFENCE_CENEMY_H


class CEnemy : public CGameObject {
public:
    static int m_Speed;

    CEnemy(char mark, int hp);
    char GetMark() const;
    void Hit(int damage);
    bool IsDead() const;
    int GetIteration() const;

private:
    char m_Mark;
    int m_MaxHealth;
    int m_CurrentHealth;
};


#endif //TOWERDEFENCE_CENEMY_H
