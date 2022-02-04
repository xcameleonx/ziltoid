#pragma once 

#include "structs.h"
#include "gfx.h"

void GameTitle(Game *game);
void GameTitle_HandleInput(u16 joy, u16 changed, u16 state);
void GameTitle_Render(Game* game);