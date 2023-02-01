#pragma once
#include "SCENE.h"
class RESULT :
    public SCENE
{
public:
    RESULT(class GAME* game);
    ~RESULT();
    void create();
    void update();
    void draw();
    void nextScene();
};

