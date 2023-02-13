#include"libOne.h"
#include"PLAYER.h"
#include"BACK.h"
#include "STAGE01.h"
#include "CONTAINER.h"
#include"GAME.h"
STAGE01::STAGE01(class GAME* game) :
	SCENE(game) {

}
STAGE01::~STAGE01(){}
void STAGE01::init(){
	game()->player()->init();
}
void STAGE01::update(){
	game()->player()->update();
}
void STAGE01::draw() {
	clear();
	game()->draw();
	
}
//ƒV[ƒ“Ø‚è‘Ö‚¦
void STAGE01::nextScene(){
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::RESULT_ID);
	}
}
