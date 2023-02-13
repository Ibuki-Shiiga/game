#include"libOne.h"
#include"CONTAINER.h"
#include "RESULT.h"
#include"GAME.h"
RESULT::RESULT(GAME* game):
	SCENE(game)
{
}
RESULT::~RESULT(){}
void RESULT::create(){
	Result = game()->container()->result();
}
void RESULT::update(){}
//•`‰æ
void RESULT::draw(){
	clear(Result.backColor);
	fill(Result.textColor);
	textSize(Result.textSize);
	text(Result.str, Result.pos.x, Result.pos.y);
}
//ƒV[ƒ“Ø‚è‘Ö‚¦
void RESULT::nextScene(){
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}

}
