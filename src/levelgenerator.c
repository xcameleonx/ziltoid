#include "levelgenerator.h"

#include "../res/resources.h"
#include "global.h"
#include "map.h"


u8** currentMap;

Vect2D_u16 roomTileSize;

void freeCollisionMap() {
    for(u16 i = 0; i < roomTileSize.y; i++) {
        MEM_free(currentMap[i]);
    }
    MEM_free(currentMap);
}


void generateCollisionMap(const u8 map[][48]) {
    roomSize = newAABB(0, bg->w, 0, bg->h);

    //level is made of 16x16 tiles, bitshifting is faster then dividing
    roomTileSize = newVect2D_u16(bg->w >> TILE_SHIFT, bg->h >> TILE_SHIFT);

    currentMap = (u8**)MEM_alloc(roomTileSize.y * sizeof(u8*));
    for(u16 i = 0; i < roomTileSize.y; i++){
        currentMap[i] = (u8*)MEM_alloc(roomTileSize.x);
        memcpy(currentMap[i], map[i], roomTileSize.x);
    }
}


u16 getTile(s16 x, s16 y) {
    if(x >= roomTileSize.x || x < 0 || y < 0 || y >= roomTileSize.y) 
        return 0;

    return currentMap[y][x];
}

