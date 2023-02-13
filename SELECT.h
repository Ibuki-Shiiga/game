#pragma once
#include "libOne.h"
#include "SCENE.h"
class SELECT :
    public SCENE
{
public:
    struct DATA {
        int selectImg;
        VECTOR2 Imgpos;
        COLOR backColor;
        COLOR textColor;
        COLOR textColor2;
        float textSize;
        float textSize2;
        VECTOR2 pos;
        char str[16];
        float eSelect_Mode01Y, eSelect_Mode01X, eSelect_Mode02Y, eSelect_Mode02X, expX, expY;
       

    };
private:
    DATA Select ;
public:
    SELECT(class GAME* game);
    ~SELECT();
    void selecter();
    void create();
    void draw();
    void nextScene();
};

