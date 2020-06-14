#include "CCoords.h"

#ifndef TOWERDEFENCE_CENEMY_H
#define TOWERDEFENCE_CENEMY_H


class CEnemy {
public:
    CEnemy(char mark, int hp);

    static int m_Speed;

    char m_Mark;
    int m_MaxHealth;
    int m_CurrentHealth;
    int m_Iteration;
    CCoords m_Pos{};
};


#endif //TOWERDEFENCE_CENEMY_H
