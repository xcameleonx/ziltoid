#include <genesis.h>
#include "global.h"

void Global_HandleInput(u16 joy, u16 changed, u16 state) 
{
    ;
}

void Init(Game* game) 
{
    SYS_disableInts();

    VDP_setScreenHeight224();
    VDP_setScreenWidth320();

    SYS_enableInts();
    game->scene = GAME_TITLE;
}