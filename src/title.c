/**
 * Ziltoid and The Quest for Coffee
 * title.c
 * Basically just manage the title screen.
 **/

#include <genesis.h>
#include "global.h"
#include "title.h"

void GameTitle(Game *game)
{
    SPR_init();
    SYS_disableInts();

    VDP_loadTileSet(title.tileset,TILE_USERINDEX,DMA);
	VDP_setPalette(PAL1, title.palette->data);
	VDP_setMap(BG_A, title.tilemap, TILE_ATTR_FULL(PAL1, 0, 0, 0, TILE_USERINDEX), 0, 0);
	SYS_enableInts();

    JOY_init();

    game->loop = TRUE;
	s16 frames = 0;
	while (game->loop)
    {
        if (frames >= 60)
        {
            SYS_disableInts();
            VDP_drawText("PRESS START BUTTON" , 10, 20);
            SYS_enableInts();
            JOY_setEventHandler(GameTitle_HandleInput);
            frames = 0;
        }
        else if (frames == 30)
        {
            SYS_disableInts();
            VDP_clearTextArea(10, 20, 18, 1);
            SYS_enableInts();
        }

        frames++;

        SPR_update();
        VDP_waitVSync();
    }
}

void GameTitle_HandleInput(u16 joy, u16 changed, u16 state)
{
    Global_HandleInput(joy, changed, state);
}

void GameTitle_Render(Game* game) 
{
}