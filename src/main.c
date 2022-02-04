/**
 * Ziltoid and The Quest for Coffee
 * main.c
 **/
#include <genesis.h>
#include "global.h"
#include "title.h"

int main()
{
    Game game;
    Init(&game);
    
    while(TRUE)
    {
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        switch(game.scene) {
            case GAME_TITLE:
                GameTitle(&game);
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