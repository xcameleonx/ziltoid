/**
 * Ziltoid and The Quest for Coffee
 * main.c
 **/
#include <genesis.h>
#include "global.h"
#include "title.h"
#include "options.h"

int main()
{
    Init();
    
    while(TRUE)
    {
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        switch(game.scene) {
            case GAME_TITLE:
            {
                KLog_U1("entering TITLE scene", 1);
                GameTitle();
                break;
            }
            case GAME_OPTION:
            {
                KLog_U1("entering OPTIONS scene", 1);
                GameOptions();
                break;
            }
            case GAME_PLAY:
                break;
            case GAME_OVER:
                break;
        }
    }
    return (0);
}