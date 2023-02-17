#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class ENEMYS :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        int totalNum;
        int curNum;
        float majRadius;
        float minRadius;
        VECTOR2 centerPos;
        float fallSpeed;
        float targetPosY;
        float refTheta;
        float thetaSpeed;
        float triggerInterval;
        float ofstLaunchDist;
        //collision
        float bcRadius;
        float invincibleTime;
        int initHp;
        VECTOR2 hpGaugeOfst;
        COLOR collisionColor;
        COLOR normalColor;
        float advSpeed;
        float angSpeed;

    };
private:
    //共通データ
    DATA Enemy;
    //単体データ配列
    struct ENEMY {
        VECTOR2 pos;
        float ofstTheta;
        float triggerErapsedTime;
        float invincibleRestTime;
        VECTOR2 vec;

        int hp;
        COLOR color;
    };
    ENEMY* Enemies;
public:
    ENEMYS(class GAME* game);
    ~ENEMYS();
    void create();
    void init();
    void update();
     void move();
     void launch();
     void collision();
     void kill(int i);
    void draw();
    //getter
    int curNum() { return Enemy.curNum; }
    VECTOR2 pos(int i) { return Enemies[i].pos; }
    float bcRadius() { return Enemy.bcRadius; }

};



