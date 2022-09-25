#pragma once

#include <genesis.h>

#include "physics.h"
#include "types.h"
#include "camera.h"


struct pBody {
    Sprite* sprite;
    AABB aabb;
    AABB climbingAABB;

    int direction;
    int speed;
    fix16 acceleration;
    fix16 deceleration;
    int climbSpeed;
    u16 terminalFallSpeed;
    u16 jumpSpeed;

    u16 currentAnimation;

    bool onGround;
    bool onStairs;
    bool jumping;
    bool climbing;

    Vect2D_s16 position;
    Vect2D_s16 globalPosition;
    Vect2D_s16 centerOffset;

    struct {
        fix16 horizontal;
        fix16 vertical;
        s16 x;
    }velocity;

    Vect2D_s16 input;
};

extern struct pBody playerBody;

void playerInputChanged();
void playetInit();
void updatePlayer();