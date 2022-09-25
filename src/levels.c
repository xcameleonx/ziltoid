#include "levels.h"

#include "levelgenerator.h"
#include "map.h"
#include "global.h"
#include "../res/resources.h"

void loadLevel(int levelNumber) {
    //Ignore the level number for now.

    PAL_setPalette(LEVEL_PALETTE, level_palette.data, DMA);
    VDP_loadTileSet(&level_tileset, VDPTilesFilled, DMA);
    bg = MAP_create(&level_map, TILEMAP_PLANE, TILE_ATTR_FULL(LEVEL_PALETTE, FALSE, FALSE, FALSE, VDPTilesFilled));

    VDPTilesFilled += level_tileset.numTile;

    generateCollisionMap(collisiopnMap);

    //Play music when it's ready.
}