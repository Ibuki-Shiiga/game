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
//�`��
void RESULT::draw(){
	clear();
	printSize(300);
	print("RESULT");
}
//�V�[���؂�ւ�
void RESULT::nextScene(){
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}

}
