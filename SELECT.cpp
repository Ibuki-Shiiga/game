#include"libOne.h"
#include"CONTAINER.h"
#include "GAME.h"
#include "SELECT.h"
SELECT::SELECT(class GAME* game) :
	SCENE(game) {
}
SELECT::~SELECT(){}
void SELECT::create() {
	Select = game()->container()->select();
}
void SELECT::selecter(){

}
void SELECT::draw(){
		clear(Select.backColor);
		fill(Select.textColor);
		textSize(Select.textSize);
		image(Select.selectImg,Select.Imgpos.x, Select.Imgpos.y);

		

}
//シーン切り替え
void SELECT::nextScene(){
	typedef enum {
		eSelect_Mode01,
		eSelect_Mode02,

		eSelect_Num,
	} eSelect;

	static int NowSelect = eSelect_Mode01;
	if (isTrigger(KEY_DOWN)) {
		NowSelect = (NowSelect + 1) % eSelect_Num;
	}
	if (isTrigger(KEY_UP)) {
		NowSelect = (NowSelect + (eSelect_Num - 1)) % eSelect_Num;
	}
	if (isTrigger(KEY_ENTER) == 1) {
		switch (NowSelect) {
		case 0:
				game()->changeScene(GAME::STAGE01_ID);
				break;
		case 1:
				game()->changeScene(GAME::STAGE02_ID);
				break;
		}
	}
	text(Select.str, Select.pos.x, Select.pos.y);
	textSize(Select.textSize);
	text("ゲーム01",Select.eSelect_Mode01X, Select.eSelect_Mode01Y);
	text("ゲーム02", Select.eSelect_Mode02X, Select.eSelect_Mode02Y);
	if (NowSelect==0) {
		fill(Select.textColor2);
		text("ゲーム01", Select.eSelect_Mode01X, Select.eSelect_Mode01Y);
	}
	else {
		fill(Select.textColor2);
		text("ゲーム02", Select.eSelect_Mode02X, Select.eSelect_Mode02Y);
	}
	

	if (NowSelect == 0) {
		fill(Select.textColor2);
		text("ゲーム01", Select.eSelect_Mode01X, Select.eSelect_Mode01Y);
	}
	else {
		fill(Select.textColor2);
		text("ゲーム02", Select.eSelect_Mode02X, Select.eSelect_Mode02Y);
	}

	textSize(Select.textSize2);
	text("上下キーで選択　ENTARで続行", Select.expX, Select.expY);


}