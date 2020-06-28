#include "../headers/CEnemiesGenerator.h"
#include "../headers/CEnemy.h"
#include "../headers/CCrazyEnemy.h"
#include <random>
#include <sstream>
#include <fstream>

using namespace std;

CEnemiesGenerator::CEnemiesGenerator(int types, CCoords * way, int length, char ** field) {
    m_Freq = 0;
    m_MaxLength = 0;
    m_Level = 0;
    m_EnemiesInSeq = 0;
    m_CurrentSeqLength = 0;
    m_IterCounter = 0;
    m_TypesCount = types;

    m_IsCrazy = false;
    m_Field = field;

    m_Way = way;
    m_WayLength = length;

    srand(time(nullptr));

    m_CurrentType = rand() % m_TypesCount + 1;
}

// calculates new properties for a class
void CEnemiesGenerator::GetLevel(int level) {
    if (m_Level != level) {
        m_Level = level;
        m_MaxLength = level * 5;
        m_Freq = 10 * level;
    }

    // iteration counter for correct work of generator
    m_IterCounter++;
    if (m_IterCounter == m_Freq){
        m_IterCounter = 0;
    }
}

CEnemy * CEnemiesGenerator::GenerateEnemy() {
    if (m_EnemiesInSeq < m_CurrentSeqLength){
        ostringstream path;

        // get enemy properties from the file
        path << "src/templates/enemies/enemy0" << m_CurrentType;
        ifstream file;
        file.open(path.str());
        char mark;
        int hp;
        int priceGold;
        int priceDiamonds;
        file >> mark;
        file >> hp;
        file >> priceGold;
        file >> priceDiamonds;

        // creating an enemy instance
        CEnemy * enemy;
        if (m_IsCrazy)
            enemy = new CCrazyEnemy(mark, hp, priceGold, priceDiamonds, m_Field);
        else
            enemy = new CEnemy(mark, hp, priceGold, priceDiamonds, m_Way, m_WayLength);
        m_EnemiesInSeq++;
        return enemy;
    }
    else if (m_EnemiesInSeq == m_CurrentSeqLength && m_IterCounter == 0) {
        m_EnemiesInSeq = 0;

        // generating type
        m_IsCrazy = rand() % 2;

        // calculate new length of next sequence
        if (m_IsCrazy)
            m_CurrentSeqLength = 1;
        else
            m_CurrentSeqLength = rand() % m_MaxLength / 2 + m_MaxLength / 2;
        // geting new sequence type
        m_CurrentType = rand() % m_TypesCount + 1;
    }
    return nullptr;     // if enemy should not be generated
}

CEnemiesGenerator::~CEnemiesGenerator() {
    delete [] m_Way;
}
