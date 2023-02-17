#pragma once
#include "GAME_OBJECT.h"
#include "libOne.h"
class BACK :
    public GAME_OBJECT
{
public:
    struct DATA {
        int backImg;
        VECTOR2 backPos;
    };
private:
    DATA Back;

public:
    BACK(class GAME* game);
    void create();
    void draw();
};

