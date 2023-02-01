#include"libOne.h"
#include "RESULT.h"
#include"GAME.h"
RESULT::RESULT(GAME* game):
	SCENE(game)
{
}
RESULT::~RESULT(){}
void RESULT::create(){}
void RESULT::update(){}
//描画
void RESULT::draw(){
	clear();
	printSize(300);
	print("RESULT");
}
//シーン切り替え
void RESULT::nextScene(){
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}

}
