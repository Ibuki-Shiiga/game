#pragma once
#include "GAME_OBJECT.h"
#include "PLAYER_VEC.h"
#include "libOne.h"
class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        //move
        VECTOR2 pos;
        float advSpeed;
        float angle;
        float angSpeed;
        float limmitX;
        float limmitY;
        //launch
        VECTOR2 launchVec;
        float triggerErapsedTime;
        float triggerIntreval;
        float ofstLaunchDist;
        float lunchAngSpeed;
        float lunchAngle;
        //collision
        float bcRadius;
        float invincibleTime;
        float invincibleRestTime;
        int hp;
        VECTOR2 hpGaugeOfst;
        COLOR collisionColor;
        COLOR normalColor;
        COLOR color;
    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    void create();
    void init();
    void update();
        void move();
        void launch();
        void collision();
    void draw();
    void updateForGameOver();
    VECTOR2 pos() { return Player.pos; }
    int hp() { return Player.hp; }

    
};

