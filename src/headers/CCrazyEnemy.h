#include "CEnemy.h"

#ifndef TOWERDEFENCE_CCRAZYENEMY_H
#define TOWERDEFENCE_CCRAZYENEMY_H


class CCrazyEnemy : public CEnemy {
public:
    CCrazyEnemy(char mark, int hp, int gold, int diamonds, char ** field);
    void MoveToNext() override;
    ~CCrazyEnemy() override = default;

private:
    char ** m_Field;
};


#endif //TOWERDEFENCE_CCRAZYENEMY_H
