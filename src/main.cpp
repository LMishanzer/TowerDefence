#include <iostream>
#include <unistd.h>
#include "CMap.h"
#include "CRoute.h"

using namespace std;

CMap * map;


void Setup()
{
    map = new CMap();
    map->LoadMap("templates/maps/map01.txt");
    map->CompileEnemies();
    CRoute route(*map);
    map->m_Way = route.GetWay(map->m_WayLength);

//    for (int i = 0; i < map->m_WayLength; i++){
//        cout << map->m_Way[i].y << ", " << map->m_Way[i].x << endl;
//    }

//    route.Print();
//    delete enemy;
}

void Draw()
{
    system("clear");

    map->Print();
}

void Input()
{

}

void Logic()
{
    map->MoveEnemies();
    auto * enemy = new CEnemy();
    enemy->m_Mark = '@';
    map->AddEnemy(*enemy);

    map->CompileEnemies();
}

int main() {
    Setup();

    while(true)
    {
        Draw();
        Input();
        Logic();
        usleep(100000);
    }


    return 0;
}
