#include "../headers/CWallet.h"

CWallet::CWallet(int gold, int diamonds) {
    m_Gold = gold;
    m_Diamonds = diamonds;
}

void CWallet::Income(int gold, int diamonds) {
    m_Gold += gold;
    m_Diamonds += diamonds;
}

bool CWallet::Expanse(int gold, int diamonds) {
    if (m_Gold >= gold && m_Diamonds >= diamonds){
        m_Gold -= gold;
        m_Diamonds -= diamonds;
        return true;
    }
    return false;
}

int CWallet::CurrentGoldStatus() const {
    return m_Gold;
}

int CWallet::CurrentDiamondsStatus() const {
    return m_Diamonds;
}
