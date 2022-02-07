/**
 * Ziltoid and The Quest for Coffee
 * title.c
 * Basically just manage the title screen.
 **/

#include <genesis.h>
#include "global.h"
#include "title.h"

s16 t_frames = 0;
void GameTitle()
{
    GameTitle_Init();
	while (game.loop)
    {
        JOY_setEventHandler(GameTitle_HandleInput);
        if(game.exitCurrScene) 
        {
            SPR_reset();
            SPR_clear();
            game.loop = FALSE;
            game.scene = GAME_OPTION;
        }
        GameTitle_Render();
        t_frames++;       
        SPR_update();
        VDP_waitVSync();
    }
}

void GameTitle_Init() 
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

void GameTitle_HandleInput(u16 joy, u16 changed, u16 state)
{
    Global_HandleInput(joy, changed, state);
    KLog_U1("Joy  ", joy);
    KLog_U1("Changed  ", changed);
    KLog_U1("State ", state);
    if(changed & state & BUTTON_START) 
    {
        game.exitCurrScene = TRUE;
        KLog_U1("Pressed START ", 1);
    }
}

void GameTitle_Render() 
{
    if (t_frames >= 60)
    {
        SYS_disableInts();
        VDP_drawText("PRESS START BUTTON " , 10, 20);
        SYS_enableInts();
        t_frames = 0;
    }
    else if (t_frames == 30)
    {
        SYS_disableInts();
        VDP_clearTextArea(10, 20, 18, 1);
        SYS_enableInts();
    }
}