#include <ncurses.h>
#include <sstream>
#include "headers/CMap.h"
#include "headers/CRoute.h"
#include "headers/CEnemiesGenerator.h"
#include "headers/CLevel.h"
#include "headers/CWallet.h"
#include "headers/GameOver.h"
#include "headers/Winner.h"

using namespace std;

const int iterationsToNextLevel = 100;      // iterations player needs for the next level
const int mapsCount = 3;
const int enemyTypesCount = 3;              // number of enemies types
const int iterationsPerTurn = 5;            // 1 enemy move per n cycles
const int startGold = 1500;                 // amount of gold on the start
const int startDiamonds = 1;                // amount of diamonds on the start
const int levelsToWin = 5;                  // levels needed to win


CMap * map;                     // map for game
CLevel * level;                 // current level
CWallet * wallet;               // player's wallet
CEnemiesGenerator * generator;  // generator of enemies
bool isOver;                    // is game over (win or failure)
bool isInterrupted;             // is game interrupted by user
bool isWinner;                  // is game won
int iterCounter;                // iteration counter (for level counting)


/**
 * setup before game is started
 */
void Setup()
{
    srand(time(0));

    // initializing game window
    initscr();
    noecho();
    halfdelay(1);

    // setting up parameters
    isOver = false;
    isInterrupted = false;
    isWinner = false;
    iterCounter = 0;
    int mapNumber = rand() % mapsCount + 1;

    // generating instances of main game classes
    wallet = new CWallet(startGold, startDiamonds);

    // loading map from the file
    ostringstream path;
    path << "src/templates/maps/map0" << mapNumber;
    map = new CMap(path.str(), wallet);

    level = new CLevel(iterationsToNextLevel, levelsToWin);

    // creating the shortest route through the map
    CRoute route(*map);
    generator = new CEnemiesGenerator(enemyTypesCount, route.GetWay(), route.GetLength(), map->GetField());
}

/**
 * draws field and information about game
 */
void Draw()
{
    // field
    map->Print();

    // stats and other info
    printw("Gold: %d\tDiamonds: %d\n\n", wallet->CurrentGoldStatus(), wallet->CurrentDiamondsStatus());

    printw("Passed enemies: %d\n", map->PassedEnemies());
    printw("Killed enemies: %d\n", map->KilledEnemies());
    printw("Level: %d\n", level->CurrentLevel());
    printw("Press A to add a weak tower    1000 gold\n");
    printw("Press B to add a strong tower  1300 gold  1 diamond\n");
    printw("Press X to escape\n\n");
}

/**
 * reads input from the player
 */
void Input()
{
    CTower * tower;
    int number;

    // A or B to add tower, X to exit
    switch (getch()) {
        case 'a':
            tower = new CTower('A');

            if (tower->GetPriceGold() <= wallet->CurrentGoldStatus()
            && tower->GetPriceDiamonds() <= wallet->CurrentGoldStatus()) {
                printw("Enter number of the position:\n");
                halfdelay(100);
                number = getch() - 48;
                halfdelay(1);
                clear();

                if (!map->AddTower(tower, number))
                    delete tower;
            }
            else
                delete tower;
            break;
        case 'b':
            tower = new CTower('B');

            if (tower->GetPriceGold() <= wallet->CurrentGoldStatus()
                && tower->GetPriceDiamonds() <= wallet->CurrentDiamondsStatus()) {
                printw("Enter number of the position:\n");
                halfdelay(100);
                number = getch() - 48;
                halfdelay(1);
                clear();

                if (!map->AddTower(tower, number))
                    delete tower;
            }
            else
                delete tower;
            break;
        case 'x':
            isInterrupted = true;
            break;
    }
}

/**
 * realisation of game logic
 */
void Logic()
{

    if (iterCounter == iterationsPerTurn) {
        map->MoveEnemies();
        level->Next();
        isWinner = level->IsWinner();
        generator->GetLevel(level->CurrentLevel());
        auto *enemy = generator->GenerateEnemy();
        map->AddEnemy(enemy);
        isOver = map->IsOver();
        iterCounter = 0;
    }

    iterCounter++;

    map->MoveBullets();
    map->Render();
}

int main() {
    Setup();

    while(!isOver && !isInterrupted && !isWinner)
    {
        Draw();
        Input();
        Logic();
    }
    clear();

    if (!isInterrupted) {
        if (isWinner)
            Winner();
        else
            GameOver();
    }

    endwin();

    delete map;
    delete level;
    delete generator;

    return 0;
}
