#include "CCoords.h"

#ifndef TOWERDEFENCE_CTOWER_H
#define TOWERDEFENCE_CTOWER_H


class CTower {
public:
    CTower(char mark);
    CCoords GetPosition() const;
    char GetMark() const;
    void SetPosition(CCoords pos);

private:
    int m_Damage;
    int m_Range;
    int m_FireRate;
    CCoords m_Pos{};
    char m_Mark;
};


#endif //TOWERDEFENCE_CTOWER_H
