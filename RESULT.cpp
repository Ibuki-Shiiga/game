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
//描画
void RESULT::draw(){
	clear(Result.backColor);
	fill(Result.textColor);
	textSize(Result.textSize);
	text(Result.str, Result.pos.x, Result.pos.y);
}
//シーン切り替え
void RESULT::nextScene(){
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}

}
