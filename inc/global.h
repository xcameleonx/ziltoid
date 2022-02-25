#ifndef Z_GLOBAL_H
#define Z_GLOBAL_H

#include <genesis.h>
#include "structs.h"
    
Game game;
s16 frame_timer;

void Init();

void Global_HandleInput(u16 joy, u16 changed, u16 state);

#endif