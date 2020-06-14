#include <fstream>
#include "CTower.h"

using namespace std;

CTower::CTower(char mark) {
    m_Mark = mark;
    ifstream file;

    if (mark == 'A'){
        file.open("templates/enemies/A");
    }
    else if (mark == 'B'){
        file.open("templates/enemies/B");
    }

    file >> m_Damage;
    file >> m_Range;
    file >> m_FireRate;

    file.close();
}

char CTower::GetMark() const {
    return m_Mark;
}

CCoords CTower::GetPosition() const {
    return m_Pos;
}

void CTower::SetPosition(CCoords pos) {
    m_Pos = pos;
}
