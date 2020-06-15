#include "CCoords.h"

#ifndef TOWERDEFENCE_CMOVINGOBJECT_H
#define TOWERDEFENCE_CMOVINGOBJECT_H


class CGameObject{
public:
    CGameObject(){
        m_Iteration = 0;
    }

    void SetPosition(CCoords pos){
        m_Pos = pos;
    }

    CCoords GetPosition() const {
        return m_Pos;
    }

    void IncrementIterator(){
        m_Iteration++;
    }

protected:
    CCoords m_Pos{};
    int m_Iteration;
};


#endif //TOWERDEFENCE_CMOVINGOBJECT_H
