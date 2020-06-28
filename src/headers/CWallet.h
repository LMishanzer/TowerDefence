#ifndef TOWERDEFENCE_CWALLET_H
#define TOWERDEFENCE_CWALLET_H

// keeps account status
class CWallet {
public:
    CWallet(int gold, int diamonds);
    void Income(int gold, int diamonds);
    bool Expanse(int gold, int diamonds);
    int CurrentGoldStatus() const;
    int CurrentDiamondsStatus() const;

private:
    int m_Gold;
    int m_Diamonds;
};


#endif //TOWERDEFENCE_CWALLET_H
