#include <iostream>
#include <unistd.h>
#include "CMap.h"
#include "CRoute.h"
#include "CEnemiesGenerator.h"
#include "CLevel.h"
#include "GameOver.h"

using namespace std;

CMap * map;
CLevel * level;
CEnemiesGenerator * generator;
bool isOver;

void Setup()
{
    isOver = false;

    map = new CMap();
    level = new CLevel();
    generator = new CEnemiesGenerator();
    map->LoadMap("src/templates/maps/map01.txt");
    CRoute route(*map);
    map->m_Way = route.GetWay(map->m_WayLength);

    level->SetIterCount(100);

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
    cout << "Level: " << level->CurrentLevel() << endl;
}

void Input()
{

}

void Logic()
{
    map->MoveEnemies();

    level->Next();
    generator->GetLevel(level->CurrentLevel());
    auto * enemy = generator->GenerateEnemy();
    map->AddEnemy(enemy);

    isOver = map->IsOver();

    map->CompileEnemies();
}

int main() {
    Setup();

    while(!isOver)
    {
        Draw();
        Input();
        Logic();
        usleep(100000);
    }
    system("clear");
    GameOver();

    delete map;
    delete level;
    delete generator;

    return 0;
}
