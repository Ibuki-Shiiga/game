#include"libOne.h"
#include"TITLE.h"
#include"SELECT.h"
#include"STAGE01.h"
#include"STAGE02.h"
#include"RESULT.h"
#include"CONTAINER.h"
#include"GAME.h"

GAME::GAME(){
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[SELECT_ID] = new SELECT(this);
	Scenes[STAGE01_ID] = new STAGE01(this);
	Scenes[STAGE02_ID] = new STAGE02(this);
	Scenes[RESULT_ID] = new RESULT(this);
	CurSceneId = TITLE_ID;
}
GAME::~GAME() {
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
}
void GAME::run(){
	window(1920, 1080, full);

	Container->load();
	Scenes[TITLE_ID]->create();

	Scenes[CurSceneId]->init();
	while (notQuit) {
		Scenes[CurSceneId]->proc();
	}
}

void GAME::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
}