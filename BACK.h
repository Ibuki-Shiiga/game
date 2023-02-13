#pragma once
#include "GAME_OBJECT.h"
class BACK :
    public GAME_OBJECT
{
public:
    struct DATA {
        int backImg;
        float backX, backY;
    };
private:
    DATA Back;

public:
    BACK(GAME* game);
    void create();
    void draw();
};

