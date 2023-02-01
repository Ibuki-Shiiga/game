#pragma once
#include "SCENE.h"
class STAGE01 :
    public SCENE
{
public:
    STAGE01(class GAME* game);
    ~STAGE01();
    void init();
    void update();
    void draw();
    void nextScene();

};

