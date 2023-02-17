#pragma once
#include "BULLETS.h"
class PLAYER_BULLET :
    public BULLETS
{
private:
    DATA playerBullet;
public:
    PLAYER_BULLET(class GAME* game);
    void create();
    void angle();
};

