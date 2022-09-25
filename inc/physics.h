#pragma once

#include <genesis.h>

#include "types.h"

typedef enum {
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
}TILE_EDGE;

#define TILE_OFFSET 16
#define TILE_SHIFT  4

u16 getTileEdge(TILE_EDGE edge, u16 x, u16 y);
AABB getTileBounds(s16 x, s16 y);
Vect2D_u16 PositionToTile(Vect2D_s16 position); 