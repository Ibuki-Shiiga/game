#include"libOne.h"
#include"PLAYER.h"
#include"ENEMYS.h"
#include"BACK.h"
#include"STAGE01.h"
#include"PLAYER_BULLET.h"
#include"CONTAINER.h"
#include"GAME.h"
STAGE01::STAGE01(class GAME* game) :
	SCENE(game) {

}
STAGE01::~STAGE01(){}
void STAGE01::create() {
}
void STAGE01::init(){
	game()->player()->init();
	game()->enemies()->init();
	game()->playerBullet()->init();
}
void STAGE01::update(){
	game()->player()->update();
	game()->enemies()->update();
	game()->playerBullet()->update();
}
void STAGE01::draw() {
	clear();
	game()->draw();

	
}
//ƒV[ƒ“Ø‚è‘Ö‚¦
void STAGE01::nextScene(){
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::RESULT_ID);
	}
}
