/**
 * Ziltoid and The Quest for Coffee
 * title.c
 * Basically just manage the title screen.
 **/

#include "global.h"
#include "title.h"

void GameTitle()
{
    GameTitle_Init();
	while (game.loop)
    {
        JOY_setEventHandler(&GameTitle_HandleInput);
        SYS_doVBlankProcess();
        if(game.exitCurrScene) 
        {
            SPR_reset();
            SPR_clear();
            game.loop = FALSE;
            game.scene = GAME_OPTION;
        }
        GameTitle_Render();
        frame_timer++;       
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

    frame_timer = 0;
    game.loop = TRUE;
    game.exitCurrScene = FALSE;
}

void GameTitle_HandleInput(u16 joy, u16 changed, u16 state)
{
    KLog_U1("Entered the input handler: TITLE  ", 1);
    
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

void GameTitle_Render() 
{
    if (frame_timer >= 60)
    {
        SYS_disableInts();
        VDP_drawText("PRESS START BUTTON " , 10, 20);
        SYS_enableInts();
        frame_timer = 0;
    }
    else if (frame_timer == 30)
    {
        SYS_disableInts();
        VDP_clearTextArea(10, 20, 18, 1);
        SYS_enableInts();
    }
}