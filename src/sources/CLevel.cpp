#include "../headers/CLevel.h"

CLevel::CLevel(int iterations, int toWin) {
    m_Level = 1;
    m_IterCount = 0;
    m_IterToNext = iterations;
    m_LevelsToWin = toWin;
}

void CLevel::Next() {
    m_IterCount++;

    if (IsNextLevel()){
        m_Level++;
    }
}

bool CLevel::IsNextLevel() const {
    return m_IterCount != 0 && m_IterCount % m_IterToNext == 0;
}

int CLevel::CurrentLevel() const {
    return m_Level;
}

bool CLevel::IsWinner() const {
    return m_Level == m_LevelsToWin;
}
