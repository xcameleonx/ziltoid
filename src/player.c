#include "player.h"

#include "global.h"
#include "map.h"
#include "resources.h"

struct pBody playerBody;

void checkCollisions();
void updateAnimations();

const s16 time = 10;
s16 currentTime;

const s16 jumpBufferTime = 10;
s16 currentJumpBufferTime;

bool collidingStairs;
bool running;

const u16 dieDelay = 10;
const u16 oneWayPlatformErrorCorrection = 5;

s16 stairLeftEdge;
const s16 stairPositionOffset = 4;

void playerInit() {
    playerBody.sprite = SPR_addSprite(&player_sprite, levelStartPosition.x, levelStartPosition.y, TILE_ATTR(PLAYER_PALETTE, FALSE, FALSE, FALSE));
    PAL_setPalette(PLAYER_PALETTE, player_sprite.palette->data, DMA);

    playerBody.globalPosition = levelStartPosition;
    playerBody.aabb = newAABB(4, 20, 2, 24);

    playerBody.climbingAABB = newAABB(8, 20, playerBody.aabb.min.y, playerBody.aabb.max.y);
    
    //Calculate the midpoint of the sprite
    playerBody.centerOffset = (Vect2D_s16) {
        (playerBody.aabb.min.x + playerBody.aabb.max.x) >> 1,
        (playerBody.aabb.min.y + playerBody.aabb.max.y) >> 1
    };

    //Set some default values
    playerBody.speed = 2;
    playerBody.climbSpeed = 1;
    playerBody.terminalFallSpeed = 6;
    playerBody.jumpSpeed = 7;
    playerBody.direction = 1;
    playerBody.acceleration = FIX16(0.25);
    playerBody.deceleration = FIX16(0.2);

    //Set up some sound effects stuff here.
}

void playetInputChanged() {
    u16 joy = Input.joy;
    u16 state = Input.state;
    u16 changed = Input.changed;

    if(joy == JOY_1) {

        //Update horizontal movement
        if(state & BUTTON_RIGHT) {
            playerBody.input.x = 1;
        } else if (state & BUTTON_LEFT) {
            playerBody.input.x = -1;
        } else if ((changed & BUTTON_RIGHT) | (changed | BUTTON_LEFT)) {
            playerBody.input.x = 0;
        }

        //Jumping!
        if(changed & (BUTTON_A | BUTTON_B | BUTTON_C)) {
            if(state & (BUTTON_A | BUTTON_B | BUTTON_C)) {
                if(playerBody.climbing){ 
                    playerBody.climbing = FALSE;
                } else {
                    currentJumpBufferTime = jumpBufferTime;
                }
            }else if (playerBody.jumping && playerBody.velocity.vertical < 0) {
                playerBody.velocity.horizontal = fix16Mul(playerBody.velocity.vertical, FIX16(0.5));
            }
        }

    }
}