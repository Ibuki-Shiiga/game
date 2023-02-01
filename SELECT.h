#pragma once
#include "SCENE.h"
class SELECT :
    public SCENE
{
public:
    SELECT(class GAME* game);
    ~SELECT();
    void draw();
    void nextScene();
};

