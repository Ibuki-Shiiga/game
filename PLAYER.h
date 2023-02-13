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
        float limmitW;
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
};
//ƒxƒNƒgƒ‹‚Ì‘å‚«‚³

