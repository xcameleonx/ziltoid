#pragma once
#include <genesis.h>
#include "structs.h"
    
Game game;

void Init();

void Global_HandleInput(u16 joy, u16 changed, u16 state);