#include "../headers/CLevel.h"

CLevel::CLevel() {
    m_Level = 1;
    m_IterCount = 0;
    m_IterToNext = 500;
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

int & CLevel::CurrentLevel() {
    return m_Level;
}

void CLevel::SetIterCount(int count) {
    m_IterToNext = count;
}
