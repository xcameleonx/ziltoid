/**
 * Ziltoid and The Quest for Coffee
 * options.c
 * Basically just manage the options screen.
 **/

#include "global.h"
#include "options.h"

void GameOptions()
{
    GameOptions_Init();
	while (game.loop)
    {
        JOY_setEventHandler(&GameOptions_HandleInput);
        SYS_doVBlankProcess();
        if(game.exitCurrScene) 
        {
            SPR_reset();
            SPR_clear();
            game.loop = FALSE;
            game.scene = GAME_TITLE;
        }
        GameOptions_Render();
        frame_timer++;
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
    frame_timer = 0;
    game.loop = TRUE;
    game.exitCurrScene = FALSE;
}

void GameOptions_HandleInput(u16 joy, u16 changed, u16 state)
{
    KLog_U1("Entered the input handler: OPTIONS  ", 1);
    
    Global_HandleInput(joy, changed, state);
    if (joy == JOY_1)
	{
		if (state & BUTTON_START)
		{
			//player 1 press START button
            game.exitCurrScene = TRUE;
            KLog_U1("Pressed START ", 1);
		}
		else if (changed & BUTTON_START)
		{
			//player 1 released START button	
		}
    }
}

void GameOptions_Render() 
{
    if (frame_timer >= 60)
    {
        SYS_disableInts();
        VDP_drawText("I AM THE OPTIONS SCREEN", 10, 20);
        SYS_enableInts();
        JOY_setEventHandler(GameOptions_HandleInput);
        frame_timer = 0;
    }
    else if (frame_timer == 30)
    {
        SYS_disableInts();
        VDP_clearTextArea(10, 20, 23, 1);
        SYS_enableInts();
    }
    SPR_update();
    VDP_waitVSync();
}