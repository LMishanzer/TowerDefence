#include <utility>
#include "CMap.h"

#ifndef TOWERDEFENCE_CROUTE_H
#define TOWERDEFENCE_CROUTE_H


class CRoute {
public:
    explicit CRoute(CMap &map);
    CCoords * GetWay(int &i) const;
    void Print();
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
