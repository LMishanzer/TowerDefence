#include "../headers/CBullet.h"

CBullet::CBullet(CCoords * way, int length, int damage) {
    m_Way = way;
    m_Damage = damage;
    m_WayLength = length;
    m_Mark = '.';
    m_Pos = {0, 0};
    m_Iteration = 1;
}

int CBullet::Damage() const {
    return m_Damage;
}

bool CBullet::IsEnd() const {
    return m_Iteration == m_WayLength;
}

void CBullet::IncrementIterator() {
    if (!IsEnd()){
        m_Pos = m_Way[m_Iteration];
        CGameObject::IncrementIterator();
    }
}

CBullet::~CBullet() {
    delete [] m_Way;
}
