#include <utility>
#include "CMap.h"

#ifndef TOWERDEFENCE_CROUTE_H
#define TOWERDEFENCE_CROUTE_H

// builds a way for the enemies
class CRoute {
public:
    explicit CRoute(CMap &map);
    CRoute(char ** field, int width, int height, CCoords start, CCoords finish);
    CCoords * GetWay() const;       // return a way saved to m_Way
    int GetLength() const;          // length of the way
    ~CRoute();

private:
    int m_Width, m_Height;
    int ** m_RouteMap;
    int m_WayLength;
    CCoords * m_Way{};
    CCoords m_Start{};
    CCoords m_Finish{};

    void Build(CCoords current);    // builds way
    void SaveWay();                 // saves way to the m_Way
};


#endif //TOWERDEFENCE_CROUTE_H
