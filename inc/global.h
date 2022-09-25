#ifndef Z_GLOBAL_H
#define Z_GLOBAL_H

#include <genesis.h>
#include "structs.h"
#include "physics.h"
    
#define TILEMAP_PLANE BG_A
#define PLAYER_PALETTE PAL1
#define LEVEL_PALETTE PAL0

#define GROUND_TILE 1
#define LADDER_TILE 2
#define ONE_WAY_PLAT_TILE 4

extern const fix16 gravityScale;


struct {
    u16 joy;
    u16 changed;
    u16 state;
}Input;

Game game;
s16 frame_timer;

void Init();

void Global_HandleInput(u16 joy, u16 changed, u16 state);


extern Map* bg;
extern AABB roomSize;
extern AABB playerBounds;

extern u16 VDPTilesFilled;

#endif