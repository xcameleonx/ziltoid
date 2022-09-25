#include "global.h"

const fix16 gravityScale = FIX16(0.5);

Map* bg;

AABB roomSize;
AABB playerBounds;

u16 VDPTilesFilled = TILE_USER_INDEX;



void Global_HandleInput(u16 joy, u16 changed, u16 state) 
{
    KLog_U1("Entered the input handler: GLOBAL  ", 1);

    KLog_U1("GLOBAL - joy:", joy);
    KLog_U1("GLOBAL - changed:", changed);
    KLog_U1("GLOBAL - state:", state);
}

void Init() 
{
    SYS_disableInts();

    VDP_setScreenHeight224();
    VDP_setScreenWidth320();

    SYS_enableInts();
    frame_timer = 0;
    game.scene = GAME_TITLE;
}