#include "CEnemy.h"

#ifndef TOWERDEFENCE_CENEMIESGENERATOR_H
#define TOWERDEFENCE_CENEMIESGENERATOR_H


class CEnemiesGenerator {
public:
    static int TypesCount;

    CEnemiesGenerator();
    CEnemy * GenerateEnemy();
    void GetLevel(int level);

private:
    int m_Freq;
    int m_MaxLength;
    int m_EnemiesInSeq;
    int m_Level;
    int m_CurrentSeqLength;
    int m_IterCounter;
    int m_CurrentType;
};


#endif //TOWERDEFENCE_CENEMIESGENERATOR_H
