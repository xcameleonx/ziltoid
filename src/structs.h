#pragma once

enum GAME_SCENE {
    GAME_TITLE,
    GAME_OPTION,
    GAME_PLAY,
    GAME_OVER
};

typedef struct
{
    enum GAME_SCENE scene;
    bool exitCurrScene;
    bool loop;
    s16 hiScore;
} Game;