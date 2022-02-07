/**
 * Ziltoid and The Quest for Coffee
 * options.c
 * Basically just manage the options screen.
 **/

#include <genesis.h>
#include "global.h"
#include "options.h"

s16 o_frames = 0;
void GameOptions()
{
    GameOptions_Init();
	while (game.loop)
    {
        if(game.exitCurrScene) 
        {
            SPR_reset();
            SPR_clear();
            game.loop = FALSE;
            game.scene = GAME_TITLE;
        }
        GameOptions_Render();
        o_frames++;
    }
}

void GameOptions_Init() 
{
    SPR_init();
    SYS_disableInts();

    VDP_loadTileSet(title.tileset,TILE_USERINDEX,DMA);
	VDP_setPalette(PAL1, title.palette->data);
	VDP_setMap(BG_A, title.tilemap, TILE_ATTR_FULL(PAL1, 0, 0, 0, TILE_USERINDEX), 0, 0);
	SYS_enableInts();

    JOY_init();

    SPR_update();

    game.loop = TRUE;
    game.exitCurrScene = FALSE;
}

void GameOptions_HandleInput(u16 joy, u16 changed, u16 state)
{
    Global_HandleInput(joy, changed, state);
    if(changed & state & BUTTON_START) 
    {
        game.exitCurrScene = TRUE;
    }
}

void GameOptions_Render() 
{
    if (o_frames >= 60)
    {
        SYS_disableInts();
        VDP_drawText("I AM THE OPTIONS SCREEN", 10, 20);
        SYS_enableInts();
        JOY_setEventHandler(GameOptions_HandleInput);
        o_frames = 0;
    }
    else if (o_frames == 30)
    {
        SYS_disableInts();
        VDP_clearTextArea(10, 20, 18, 1);
        SYS_enableInts();
    }
    SPR_update();
    VDP_waitVSync();
}