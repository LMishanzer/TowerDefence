#include "CEnemiesGenerator.h"
#include <random>
#include <iostream>

using namespace std;

CEnemiesGenerator::CEnemiesGenerator() {
    m_Freq = 0;
    m_MaxLength = 0;
    m_Level = 0;
    m_EnemiesInSeq = 0;
    m_CurrentSeqLength = 0;
    m_IterCounter = 0;

    srand(time(nullptr));
}

void CEnemiesGenerator::GetLevel(int level) {
    if (m_Level != level) {
        m_Level = level;
        m_MaxLength = level * 5;
        m_Freq = 50 - level;
    }
    m_IterCounter++;
    if (m_IterCounter == m_Freq){
        m_IterCounter = 0;
    }
}

CEnemy * CEnemiesGenerator::GenerateEnemy() {
    if (m_EnemiesInSeq < m_CurrentSeqLength){
        auto * enemy = new CEnemy();
        enemy->m_Mark = '@';
        enemy->m_Health = 100500;
        m_EnemiesInSeq++;
        return enemy;
    }
    else if (m_EnemiesInSeq == m_CurrentSeqLength && m_IterCounter == 0) {
        m_EnemiesInSeq = 0;
        m_CurrentSeqLength = rand() % m_MaxLength;
        while (m_CurrentSeqLength < m_MaxLength / 2){
            m_CurrentSeqLength = rand() % m_MaxLength;
        }
    }
    return nullptr;
}
