#include"libOne.h"
#include"TITLE.h"
#include"SELECT.h"
#include"STAGE01.h"
#include"STAGE02.h"
#include"RESULT.h"
#include"PLAYER_VEC.h"
#include "PLAYER.h"
#include"ENEMYS.h"
#include "PLAYER_BULLET.h"
#include"CONTAINER.h"
#include"GAME.h"

GAME::GAME(){
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[SELECT_ID] = new SELECT(this);
	Scenes[STAGE01_ID] = new STAGE01(this);
	Scenes[STAGE02_ID] = new STAGE02(this);
	Scenes[RESULT_ID] = new RESULT(this);

	Back = new BACK(this);
	Player = new PLAYER(this);
	Enemies = new ENEMYS(this);
	PlayerBullet = new PLAYER_BULLET(this);

}
GAME::~GAME() {
	delete Back;
	delete PlayerBullet;
	delete Player;
	delete Enemies;
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
	delete Container;
}
void GAME::run(){
	window(1920, 1080, full);

	Container->load();
	Scenes[TITLE_ID]->create();
	Scenes[SELECT_ID]->create();
	Scenes[RESULT_ID]->create();
	Back->create();
	Player->create();
	Enemies->create();
	PlayerBullet->create();

	CurSceneId = TITLE_ID;
	Scenes[CurSceneId]->init();
	while (notQuit) {
		setDeltaTime();
		Scenes[CurSceneId]->proc();
	}
}

void GAME::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
}

void GAME::draw() {
	Back->draw();
	PlayerBullet->draw();
	Player->draw();
	Enemies->draw();
}