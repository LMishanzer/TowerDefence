#include <utility>
#include "CMap.h"

#ifndef TOWERDEFENCE_CROUTE_H
#define TOWERDEFENCE_CROUTE_H


class CRoute {
public:
    explicit CRoute(CMap &map);
    CRoute(char ** field, int width, int height, CCoords start, CCoords finish);
    CCoords * GetWay() const;
    int GetLength() const;
    ~CRoute();

private:
    int m_Width, m_Height;
    int ** m_RouteMap;
    int m_WayLength;
    CCoords * m_Way{};
    CCoords m_Start{};
    CCoords m_Finish{};

    void Build(CCoords current);
    void SaveWay();
};


#endif //TOWERDEFENCE_CROUTE_H
