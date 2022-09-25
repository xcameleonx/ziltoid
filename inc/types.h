#pragma once

#include <genesis.h>

#define clamp01(value) clamp(0, 1, value)

typedef struct  {
    u8 x;
    u8 y;
}Vect2D_u8;


typedef struct {
    s8 x;
    s8 y;
}Vect2D_s8;

typedef struct {
    Vect2D_s16 min;
    Vect2D_s16 max;
}AABB;

AABB newAABB(s16 x1, s16 x2, s16 y1, s16 y2);

Vect2D_f16 newVect2D_f16(f16 x, f16 y);
Vect2D_f32 newVect2D_f32(f32 x, f32 y);

Vect2D_s8 newVect2D_s8(s8 x, s8 y);
Vect2D_s16 newVect2D_s16(s16 x, s16 y);
Vect2D_s32 newVect2D_s32(s32 x, s32 y);

Vect2D_u8 newVect2D_u8(u8 x, u8 y);
Vect2D_u16 newVect2D_u16(u16 x, u16 y);
Vect2D_u32 newVect2D_u32(u32 x, u32 y);