#include"libOne.h"
#include "STAGE01.h"
#include"GAME.h"
STAGE01::STAGE01(class GAME* game) :
	SCENE(game) {

}
STAGE01::~STAGE01(){}
void STAGE01::init(){}
void STAGE01::update(){}
//�`��
void STAGE01::draw() {
	clear();
	printSize(300);
	print("STAGE01");
}
//�V�[���؂�ւ�
void STAGE01::nextScene(){
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::RESULT_ID);
	}
}
