#include "CEnemy.h"
#include "CTower.h"
#include "CBullet.h"
#include "CWallet.h"
#include <string>
#include <list>

using namespace std;

#ifndef TOWERDEFENCE_MAP_H
#define TOWERDEFENCE_MAP_H


/**
 * main class in the game, shows all objects on the map and implements some game logic
 */
class CMap {
public:
    CMap(string path, CWallet * wallet);
    void MoveEnemies();                         // moves enemies
    void MoveBullets();                         // moves bullets
    void Render() const;                        // save all objects in memory
    void AddEnemy(CEnemy * enemy);              // add enemy to the array
    bool AddTower(CTower * tower, int number);  // add tower to the array
    void Print() const;                         // print all objects from the memory
    bool IsOver() const;                        // is game over
    int GetWidth() const;                       // get width of the map
    int GetHeight() const;                      // get height of the map
    CCoords GetStart() const;                   // get start (point of enemies spawn)
    CCoords GetFinish() const;                  // get finish
    char ** GetField() const;                   // get field (for building the shortest way)
    int PassedEnemies() const;                  // count of passed enemies
    int KilledEnemies() const;                  // killed enemies
    ~CMap();                                    // cleans all allocated objects

private:
    int m_Width;
    int m_Height;
    char ** m_Field;

    CCoords m_Start{};
    CCoords m_Finish{};

    CWallet * m_Wallet;

    int m_MaxEnemiesCount;
    int m_EnemyCount;
    CEnemy ** m_Enemies;

    int m_MaxTowersCount;
    int m_TowersCount;
    CTower ** m_Towers;

    int m_BulletCount;
    CBullet ** m_Bullets;

    int m_PassedEnemiesToOver;

    // statistics
    int m_PassedEnemies;
    int m_KilledEnemies;

    void Shoot();           // shoots to the enemy, if it's too close to one of the towers
    void IsReached(int bulletNumber);
};


#endif //TOWERDEFENCE_MAP_H
