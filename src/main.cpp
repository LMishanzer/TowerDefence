#include <iostream>
#include <unistd.h>
#include "CMap.h"
#include "CEnemy.h"

using namespace std;

CMap map;

void Setup()
{
    auto * enemy = new CEnemy();
    map.LoadMap("templates/maps/map01.txt");
    enemy->m_PosX = 3;
    enemy->m_PosY = 3;
    enemy->m_Mark = '@';
    map.AddEnemy(*enemy);
    map.CompileEnemies();
}

void Draw()
{
    system("clear");

    map.Print();
}

void Input()
{

}

void Logic()
{

}

int main() {
    Setup();

    while(true)
    {
        Draw();
        Input();
        Logic();
        usleep(10000);
    }


    return 0;
}
