#ifndef TOWERDEFENCE_CLEVEL_H
#define TOWERDEFENCE_CLEVEL_H


class CLevel {
public:
    CLevel();
    void Next();
    bool IsNextLevel() const;
    int& CurrentLevel();
    void SetIterCount(int count);

private:
    int m_Level;
    int m_IterCount;
    int m_IterToNext;
};


#endif //TOWERDEFENCE_CLEVEL_H
