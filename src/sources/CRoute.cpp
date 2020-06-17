#include "../headers/CRoute.h"
#include <iostream>
#include <iomanip>

CRoute::CRoute(CMap &map) {
    m_Start = map.GetStart();
    m_Finish = map.GetFinish();
    m_Width = map.GetWidth();
    m_Height = map.GetHeight();
    m_WayLength = 0;
    m_RouteMap = new int*[m_Height];

    for (int i = 0; i < m_Height; i++){
        m_RouteMap[i] = new int[m_Width];
        for (int j = 0; j < m_Width; j++){
            if (map.GetField()[i][j] == '#' || map.GetField()[i][j] == '<' || map.GetField()[i][j] == '>'
                || map.GetField()[i][j] == '|' || map.GetField()[i][j] == '^')
                m_RouteMap[i][j] = -10;
            if (map.GetField()[i][j] == ' ')
                m_RouteMap[i][j] = -1;
        }
    }
    m_RouteMap[m_Finish.y][m_Finish.x] = 0;

    Build(m_Finish);

    SaveWay();
}

CRoute::CRoute(char **field, int width, int height, CCoords start, CCoords finish) {
    m_Start = start;
    m_Finish = finish;
    m_Width = width;
    m_Height = height;
    m_WayLength = 0;
    m_RouteMap = new int*[m_Height];

    for (int i = 0; i < m_Height; i++){
        m_RouteMap[i] = new int[m_Width];
        for (int j = 0; j < m_Width; j++){
            if (field[i][j] == '#' || field[i][j] == '<' || field[i][j] == '>'
                || field[i][j] == '|' || field[i][j] == '^' //|| (field[i][j] >= 'A' && field[i][j] <= 'Z')
                || (field[i][j] >= '1' && field[i][j] <= '9'))
                m_RouteMap[i][j] = -10;
            else
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
//    printw("%d\n", m_WayLength);
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

CCoords * CRoute::GetWay() const {
    if (m_Way) {
        return m_Way;
    }
    return nullptr;
}

int CRoute::GetLength() const {
    return m_WayLength;
}

CRoute::~CRoute() {
    for (int i = 0; i < m_Height; i++){
        delete [] m_RouteMap[i];
    }
    delete [] m_RouteMap;
}
