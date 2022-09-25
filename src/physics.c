#include "physics.h"


u16 getTileEdge(TILE_EDGE edge, u16 x, u16 y) {
    switch(edge) {
        case LEFT:{
            return x << TILE_SHIFT;
        }
        case RIGHT:{
            return (x << TILE_SHIFT) + TILE_OFFSET;
        }
        case TOP: {
            return y << TILE_SHIFT;
        }
        case BOTTOM:{
            return (y << TILE_SHIFT) +  TILE_OFFSET;
        }
    }
}

AABB getTileBounds(s16 x, s16 y) {
    return newAABB(getTileEdge(LEFT, x, y),
                   getTileEdge(RIGHT, x, y),
                   getTileEdge(TOP, x, y),
                   getTileEdge(BOTTOM, x, y));
}

Vect2D_u16 PositionToTile(Vect2D_s16 position) {
    return newVect2D_u16(getTileEdge(LEFT, position.x, position.y),
                         getTileEdge(TOP, position.x, position.y));
}