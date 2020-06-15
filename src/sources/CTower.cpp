#include <fstream>
#include "../headers/CTower.h"

using namespace std;

CTower::CTower(char mark) : CGameObject() {
    m_Mark = mark;
    ifstream file;

    if (mark == 'A'){
        file.open("src/templates/towers/A");
    }
    else if (mark == 'B'){
        file.open("src/templates/towers/B");
    }

    file >> m_Damage;
    file >> m_Range;
    file >> m_FireRate;

    file.close();
}

char CTower::GetMark() const {
    return m_Mark;
}

int CTower::GetDamage() const {
    return m_Damage;
}

int CTower::GetRange() const {
    return m_Range;
}

bool CTower::IsShoot() const {
    return m_Iteration
}
