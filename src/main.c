/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include "structs.h"
#include "gfx.h"


Game game;
bool loop = TRUE;
void GameTitle();
void Init();

int main()
{
    Init();
    while(TRUE)
    {
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        switch(game.scene) {
            case GAME_TITLE:
                GameTitle();
                break;
            case GAME_OPTION:
                break;
            case GAME_PLAY:
                break;
            case GAME_OVER:
                break;
        }
    }
    return (0);
}

void Init() 
{
    SYS_disableInts();

    VDP_setScreenHeight224();
    VDP_setScreenWidth320();

    SYS_enableInts();
    game.scene = GAME_TITLE;
}


void GameTitle()
{
    SPR_init();
    SYS_disableInts();

    VDP_loadTileSet(title.tileset,TILE_USERINDEX,DMA);
	VDP_setPalette(PAL1, title.palette->data);
	VDP_setMap(BG_A, title.tilemap, TILE_ATTR_FULL(PAL1, 0, 0, 0, TILE_USERINDEX), 0, 0);
	SYS_enableInts();

    JOY_init();

    game.loop = TRUE;
	s16 frames = 0;
	while (game.loop)
    {
        if (frames >= 60)
        {
            SYS_disableInts();
            VDP_drawText("PRESS START BUTTON" , 10, 20);
            SYS_enableInts();
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