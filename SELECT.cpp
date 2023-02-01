#include "SELECT.h"
#include "GAME.h"
#include"libOne.h"
SELECT::SELECT(class GAME* game) :
	SCENE(game) {
}
SELECT::~SELECT(){}
//•`‰æ
void SELECT::draw(){
	clear();
	printSize(300);
	print("SELECT ZorX");
}
//ƒV[ƒ“Ø‚è‘Ö‚¦
void SELECT::nextScene(){
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE01_ID);
	}
	else if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::STAGE02_ID);
	}
}