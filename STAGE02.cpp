#include"libOne.h"
#include"BACK.h"
#include"PLAYER.h"
#include"ENEMYS.h"
#include"PLAYER_BULLET.h"
#include"STAGE02.h"
#include"GAME.h"
STAGE02::STAGE02(class GAME* game) :
	SCENE(game) {
}
STAGE02::~STAGE02(){}
void STAGE02::init(){
	game()->player()->init();
	game()->playerBullet()->init();
	game()->enemies()->init();

}
void STAGE02::update(){
	game()->player()->update();
	game()->playerBullet()->update();
	game()->enemies()->update();
}
//•`‰æ
void STAGE02::draw(){
	clear();
	game()->draw();
}
//ƒV[ƒ“Ø‚è‘Ö‚¦
void STAGE02::nextScene(){
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::RESULT_ID);
	}
}