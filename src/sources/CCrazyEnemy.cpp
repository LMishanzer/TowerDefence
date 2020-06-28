#include "../headers/CCrazyEnemy.h"
#include <random>

CCrazyEnemy::CCrazyEnemy(char mark, int hp, int gold, int diamonds, char ** field)
: CEnemy(mark, hp, gold, diamonds, nullptr, 0) {
    m_Field = field;

    srand(time(0));
}

void CCrazyEnemy::MoveToNext() {
    bool flag = true;
    while (flag)
        switch(rand() % 4) {
            case 0:
                if (m_Field[m_Pos.y][m_Pos.x + 1] == ' ') {
                    m_Pos.x += 1;
                    flag = false;
                }
                break;

            case 1:
                if (m_Field[m_Pos.y][m_Pos.x - 1] == ' ') {
                    m_Pos.x -= 1;
                    flag = false;
                }
                break;

            case 2:
                if (m_Field[m_Pos.y + 1][m_Pos.x] == ' ') {
                    m_Pos.y += 1;
                    flag = false;
                }
                break;

            case 3:
                if (m_Field[m_Pos.y - 1][m_Pos.x] == ' ') {
                    m_Pos.y -= 1;
                    flag = false;
                }
                break;
        }
}
