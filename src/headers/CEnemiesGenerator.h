#include "CEnemy.h"

#ifndef TOWERDEFENCE_CENEMIESGENERATOR_H
#define TOWERDEFENCE_CENEMIESGENERATOR_H

/**
 * class for generating enemies by sequences of certain type during the game
 */
class CEnemiesGenerator {
public:
    explicit CEnemiesGenerator(int types, CCoords * way, int length, char ** field);
    CEnemy * GenerateEnemy();   // generate an enemy (nullptr if enemy is not needed)
    void GetLevel(int level);   // get current level for calculating m_MaxLength
    ~CEnemiesGenerator();

private:
    int m_Freq;                 // frequency of generating enemy sequences
    int m_MaxLength;            // maximal length of sequences
    int m_EnemiesInSeq;         // current number of enemies in a sequence
    int m_Level;                // current level
    int m_CurrentSeqLength;     // how many enemies should be in current sequence
                                // (random number between m_MaxLength / 2 and m_MaxLength)
    int m_IterCounter;          // iteration counter
    int m_CurrentType;          // current type of enemies in sequence
    int m_TypesCount;           // count of enemy types

    bool m_IsCrazy;

    char ** m_Field;

    CCoords * m_Way;
    int m_WayLength;
};


#endif //TOWERDEFENCE_CENEMIESGENERATOR_H
