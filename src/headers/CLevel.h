#ifndef TOWERDEFENCE_CLEVEL_H
#define TOWERDEFENCE_CLEVEL_H

// class for level counting
class CLevel {
public:
    explicit CLevel(int iterations, int toWin);
    void Next();                    // passing to the next level if needed
    int CurrentLevel() const;       // returns a current level
    bool IsWinner() const;          // is player a winner

private:
    int m_Level;            // current level
    int m_IterCount;        // current iterations count
    int m_IterToNext;       // iterations needed for next level
    int m_LevelsToWin;      // level needed to win

    bool IsNextLevel() const;
};


#endif //TOWERDEFENCE_CLEVEL_H
