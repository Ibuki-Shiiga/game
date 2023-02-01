#pragma once
#include"SCENE.h"
class STAGE02:
	public SCENE
{
public:
    STAGE02(class GAME* game);
    ~STAGE02();
    void init();
    void update();
    void draw();
    void nextScene();

};

