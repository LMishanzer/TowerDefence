#include "CGameObject.h"

#ifndef TOWERDEFENCE_CMOVINGOBJECT_H
#define TOWERDEFENCE_CMOVINGOBJECT_H


class CMovingObject : public CGameObject{
public:
    CMovingObject(CCoords * way, int length){
        m_Way = way;
        m_WayLength = length;
        m_Iteration = 0;
    }

    virtual void MoveToNext(){
        m_Iteration++;
        if (!IsEnd()){
            m_Pos = m_Way[m_Iteration];
        }
    };

    bool IsEnd(){
        return m_Iteration >= m_WayLength;
    }

    virtual ~CMovingObject() = default;

protected:
    int m_WayLength;
    int m_Iteration;    // current iteration (for moving)
    CCoords * m_Way;
};


#endif //TOWERDEFENCE_CMOVINGOBJECT_H
