#include"libOne.h"
#include"STAGE02.h"
#include"GAME.h"
STAGE02::STAGE02(class GAME* game) :
	SCENE(game) {
}
STAGE02::~STAGE02(){}
void STAGE02::init(){}
void STAGE02::update(){}
//•`‰æ
void STAGE02::draw(){
	clear();
	printSize(300);
	print("STAGE02");
}
//ƒV[ƒ“Ø‚è‘Ö‚¦
void STAGE02::nextScene(){
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::RESULT_ID);
	}
}