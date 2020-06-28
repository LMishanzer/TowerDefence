#include "CCoords.h"

#ifndef TOWERDEFENCE_CGAMEOBJECT_H
#define TOWERDEFENCE_CGAMEOBJECT_H

// class for moving objects in the game (enemies, towers, bullets)
class CGameObject{
public:
    CGameObject() = default;

    void SetPosition(CCoords pos){
        m_Pos = pos;
    }

    CCoords GetPosition() const {
        return m_Pos;
    }

    char GetMark() const{
        return m_Mark;
    }

protected:
    char m_Mark;        // marking (for example enemies can mark @)
    CCoords m_Pos{};    // current position on the map
};


#endif //TOWERDEFENCE_CGAMEOBJECT_H
