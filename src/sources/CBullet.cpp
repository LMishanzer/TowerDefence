#include "../headers/CBullet.h"

CBullet::CBullet(CCoords * way, int length, int damage) : CMovingObject(way, length) {
    m_Damage = damage;
    m_Mark = '.';
    m_Pos = {0, 0};
}

int CBullet::Damage() const {
    return m_Damage;
}

CBullet::~CBullet() {
    delete [] m_Way;
}
