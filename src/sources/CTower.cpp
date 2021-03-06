#include <fstream>
#include "../headers/CTower.h"
#include "../headers/CRoute.h"

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
    file >> m_PriceGold;
    file >> m_PriceDiamonds;

    file.close();
}

int CTower::GetRange() const {
    return m_Range;
}

CBullet * CTower::Shoot(char ** field, int width, int height, CCoords target) {
    CRoute route(field, width, height, m_Pos, target);
    auto * bullet = new CBullet(route.GetWay(), route.GetLength(), m_Damage);
    bullet->SetPosition(m_Pos);
    return bullet;
}

int CTower::GetPriceGold() const {
    return m_PriceGold;
}

int CTower::GetPriceDiamonds() const {
    return m_PriceDiamonds;
}
