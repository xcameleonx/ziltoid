#pragma once 

#include "structs.h"
#include "gfx.h"

void GameTitle();
void GameTitle_Init();
void GameTitle_HandleInput(u16 joy, u16 changed, u16 state);
void GameTitle_Render();