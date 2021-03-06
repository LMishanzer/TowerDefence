#ifndef TOWERDEFENCE_CCOORDS_H
#define TOWERDEFENCE_CCOORDS_H

/**
 * instances of this class will keep position on the map
 */
class CCoords{
public:
    int y, x;

    bool operator==(CCoords coords) const {
        return x == coords.x && y == coords.y;
    }

    bool operator!=(CCoords coords) const {
        return x != coords.x || y != coords.y;
    }
};

#endif //TOWERDEFENCE_CCOORDS_H
