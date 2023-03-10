#include"libOne.h"
#include"CONTAINER.h"
#include"GAME.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game) :
	SCENE(game) {
}
TITLE::~TITLE(){}
void TITLE::create() {
	Title = game()->container()->title();
}
//描画
void TITLE::draw(){
	/*
	clear(Title.backColor);
	fill(Title.textColor);
	textSize(Title.textSize);
	text(Title.str, Title.pos.x, Title.pos.y);
	*/
	rectMode(CENTER);
	image(Title.titleImg, Title.pos.x, Title.pos.y);
}
//シーン切り替え
void TITLE::nextScene(){
	if(isTrigger(KEY_ENTER)){
		game()->changeScene(GAME::SELECT_ID);
	}
}
