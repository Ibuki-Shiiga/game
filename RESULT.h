#pragma once
#include "SCENE.h"
#include "libOne.h"
class RESULT :
    public SCENE
{
public:
    struct DATA {
        COLOR backColor;
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        char str[16];
    };
private:
    DATA Result;

public:
    RESULT(class GAME* game);
    ~RESULT();
    void create();
    void update();
    void draw();
    void nextScene();
};

