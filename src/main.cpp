#include <ncurses.h>
#include "headers/CMap.h"
#include "headers/CRoute.h"
#include "headers/CEnemiesGenerator.h"
#include "headers/CLevel.h"
#include "headers/GameOver.h"

using namespace std;

CMap * map;
CLevel * level;
CEnemiesGenerator * generator;
bool isOver;
bool isInterrupted;
int totalSpeed;
int iterCounter;

void Setup()
{
    initscr();
    noecho();
    halfdelay(1);
    isOver = false;
    isInterrupted = false;
    totalSpeed = 2;
    iterCounter = 0;

    map = new CMap();
    level = new CLevel();
    generator = new CEnemiesGenerator();
    map->LoadMap("src/templates/maps/map01.txt");
    CRoute route(*map);
    map->SetWay(route.GetWay(), route.GetWayLength());
}

void Draw()
{
    map->Print();
    printw("Level: %d\n", level->CurrentLevel());
    printw("Press A to add a weak tower\n");
    printw("Press B to add a strong tower\n");
    printw("Press X to escape\n");
}

void Input()
{
    CTower * tower;
    int number;
    switch (getch()) {
        case 'a':
            tower = new CTower('A');
            printw("Enter number of the position:\n");

            halfdelay(100);
            number = getch() - 48;
            halfdelay(1);
            clear();

            if (!map->AddTower(tower, number))
                delete tower;
            break;
        case 'b':
            tower = new CTower('B');

            printw("Enter number of the position:\n");

            halfdelay(100);
            number = getch() - 48;
            halfdelay(1);
            clear();

            if (!map->AddTower(tower, number))
                delete tower;
            break;
        case 'x':
            isInterrupted = true;
            break;
    }
}

void Logic()
{
    if (iterCounter == totalSpeed) {
        map->MoveEnemies();
        level->Next();
        generator->GetLevel(level->CurrentLevel());
        auto *enemy = generator->GenerateEnemy();
        map->AddEnemy(enemy);
        isOver = map->IsOver();
        iterCounter = 0;
    }
    iterCounter++;

    map->CompileEnemies();
}

int main() {
    Setup();

    while(!isOver && !isInterrupted)
    {
        Draw();
        Input();
        Logic();
    }
    clear();

    if (!isInterrupted)
        GameOver();

    endwin();

    delete map;
    delete level;
    delete generator;

    return 0;
}
