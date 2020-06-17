#include "../headers/CEnemiesGenerator.h"
#include "../headers/CEnemy.h"
#include <random>
#include <sstream>
#include <fstream>

using namespace std;

CEnemiesGenerator::CEnemiesGenerator() {
    m_Freq = 0;
    m_MaxLength = 0;
    m_Level = 0;
    m_EnemiesInSeq = 0;
    m_CurrentSeqLength = 0;
    m_IterCounter = 0;

//    CEnemy::m_Speed = 10;

    srand(time(nullptr));

    m_CurrentType = rand() % TypesCount + 1;
}

void CEnemiesGenerator::GetLevel(int level) {
    if (m_Level != level) {
        m_Level = level;
        m_MaxLength = level * 5;
        m_Freq = 20;
    }
    m_IterCounter++;
    if (m_IterCounter == m_Freq){
        m_IterCounter = 0;
    }
}

CEnemy * CEnemiesGenerator::GenerateEnemy() {
    if (m_EnemiesInSeq < m_CurrentSeqLength){
        ostringstream path;
        path << "src/templates/enemies/enemy0" << m_CurrentType;
        ifstream file;
        file.open(path.str());
        char mark;
        int hp;
        file >> mark;
        file >> hp;
        auto * enemy = new CEnemy(mark, hp);
        m_EnemiesInSeq++;
        return enemy;
    }
    else if (m_EnemiesInSeq == m_CurrentSeqLength && m_IterCounter == 0) {
        m_EnemiesInSeq = 0;
        m_CurrentSeqLength = rand() % m_MaxLength;
        while (m_CurrentSeqLength < m_MaxLength / 2){
            m_CurrentSeqLength = rand() % m_MaxLength;
        }
        m_CurrentType = rand() % TypesCount + 1;
    }
    return nullptr;
}
