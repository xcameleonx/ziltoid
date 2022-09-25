#pragma once


#include <genesis.h>

#include "types.h"
#include "physics.h"
#include "player.h"
#include "levels.h"


extern Vect2D_s16 cameraPosition;

void setupCamera(Vect2D_s16 deadZoneCenter, Vect2D_u16 deadZoneDimensions);
void updateCamera();