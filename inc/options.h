#pragma once

#include "structs.h"
#include "gfx.h"

void GameOptions();
void GameOptions_Init();
void GameOptions_HandleInput(u16 joy, u16 changed, u16 state);
void GameOptions_Render();