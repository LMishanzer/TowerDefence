#include "CCoords.h"

#ifndef TOWERDEFENCE_CENEMY_H
#define TOWERDEFENCE_CENEMY_H


class CEnemy {
public:
    static int m_Speed;
    int m_Iteration;

    CEnemy(char mark, int hp);
    CCoords GetPosition() const;
    void SetPosition(CCoords pos);
    char GetMark() const;
    void Hit(int damage);
    bool IsDead() const;

private:
    char m_Mark;
    int m_MaxHealth;
    int m_CurrentHealth;
    CCoords m_Pos{};
};


#endif //TOWERDEFENCE_CENEMY_H
