#include "CRoute.h"
#include <iostream>
#include <iomanip>

CRoute::CRoute(CMap &map) {
    m_Start = map.m_Start;
    m_Finish = map.m_Finish;
    m_Width = map.m_Width;
    m_Height = map.m_Height;
    m_WayLength = 0;
    m_RouteMap = new int*[map.m_Height];

    for (int i = 0; i < m_Height; i++){
        m_RouteMap[i] = new int[m_Width];
        for (int j = 0; j < map.m_Width; j++){
            if (map.m_Field[i][j] == '#' || map.m_Field[i][j] == '<' || map.m_Field[i][j] == '>'
                || map.m_Field[i][j] == '|' || map.m_Field[i][j] == '^')
                m_RouteMap[i][j] = -10;
            if (map.m_Field[i][j] == ' ')
                m_RouteMap[i][j] = -1;
        }
    }
    m_RouteMap[m_Finish.y][m_Finish.x] = 0;

    Build(m_Finish);

    SaveWay();
}

void CRoute::Build(CCoords current) {
    if (current == m_Start)
        return;

    if (m_RouteMap[current.y + 1][current.x] == -1
    || m_RouteMap[current.y + 1][current.x] > m_RouteMap[current.y][current.x] + 1){
        m_RouteMap[current.y + 1][current.x] = m_RouteMap[current.y][current.x] + 1;
        Build({current.y + 1, current.x});
    }

    if (m_RouteMap[current.y - 1][current.x] == -1
        || m_RouteMap[current.y - 1][current.x] > m_RouteMap[current.y][current.x] + 1){
        m_RouteMap[current.y - 1][current.x] = m_RouteMap[current.y][current.x] + 1;
        Build({current.y - 1, current.x});
    }

    if (m_RouteMap[current.y][current.x - 1] == -1
        || m_RouteMap[current.y][current.x - 1] > m_RouteMap[current.y][current.x] + 1){
        m_RouteMap[current.y][current.x - 1] = m_RouteMap[current.y][current.x] + 1;
        Build({current.y, current.x - 1});
    }

    if (m_RouteMap[current.y][current.x + 1] == -1
        || m_RouteMap[current.y][current.x + 1] > m_RouteMap[current.y][current.x] + 1){
        m_RouteMap[current.y][current.x + 1] = m_RouteMap[current.y][current.x] + 1;
        Build({current.y, current.x + 1});
    }
}

void CRoute::SaveWay() {
    m_WayLength = m_RouteMap[m_Start.y][m_Start.x] + 1;
    m_Way = new CCoords[m_WayLength];

    CCoords current = m_Start;

    for (int i = 0; i < m_WayLength; i++){
        m_Way[i] = current;
        if (m_RouteMap[current.y + 1][current.x] == m_WayLength - 2 - i){
            current = {current.y + 1, current.x};
        }
        else if (m_RouteMap[current.y - 1][current.x] == m_WayLength - 2 - i){
            current = {current.y - 1, current.x};
        }
        else if (m_RouteMap[current.y][current.x - 1] == m_WayLength - 2 - i){
            current = {current.y, current.x - 1};
        }
        else if (m_RouteMap[current.y][current.x + 1] == m_WayLength - 2 - i){
            current = {current.y, current.x + 1};
        }
    }
}

void CRoute::Print() {
    for (int i = 0; i < m_Height; i++){
        for (int j = 0; j < m_Width; j++)
            if (m_RouteMap[i][j] == -10)
                cout << setw(2) << '#';
            else if (m_RouteMap[i][j] == -1)
                cout << setw(2) << ' ';
            else
                cout << setw(2) << m_RouteMap[i][j];
        cout << endl;
    }
    cout << endl;
}

CCoords * CRoute::GetWay() const {
    if (m_Way) {
        return m_Way;
    }
    return nullptr;
}

int CRoute::GetWayLength() const {
    return m_WayLength;
}

CRoute::~CRoute() {
    for (int i = 0; i < m_Height; i++){
        delete [] m_RouteMap[i];
    }
    delete [] m_RouteMap;
}
