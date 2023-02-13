#include "CONTAINER.h"
#include "GAME.h"
#include "libOne.h"
void CONTAINER::load() {
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	//タイトル
	//Data.title.backColor = COLOR(0,20,0);
	//Data.title.textColor = COLOR(0,255,255);
	//Data.title.textSize = 400;
	Data.title.pos.x = width/2;
	Data.title.pos.y = height/2;
	//strcpy_s(Data.title.str, "TITLE");
	
	//セレクト画面]	
	//Data.select.backColor = COLOR(0, 50, 0);
	Data.select.textColor = COLOR(0, 255, 0);
	Data.select.textSize = 150;
	Data.select.pos.x = 100;
	Data.select.pos.y = 300;
	strcpy_s(Data.select.str, "＜メニュー＞"); 

	Data.select.textSize2 = 30;
	Data.select.expX = 1000;
	Data.select.expY = 1000;
	Data.select.eSelect_Mode01Y = height/2;
	Data.select.eSelect_Mode01X = width/2;
	Data.select.eSelect_Mode02Y = 800;
	Data.select.eSelect_Mode02X = width/2;
	Data.select.textColor2 = COLOR(255, 0, 0);
	Data.select.Imgpos.x = width / 2;
	Data.select.Imgpos.y = height / 2;

	//ステージ１
	Data.back.backX = 540;
	Data.back.backY = 960;

	//リザルト
	Data.result.backColor = COLOR(0, 30, 0);
	Data.result.textColor = COLOR(0, 255, 0);
	Data.result.textSize = 150;
	Data.result.pos.x = 100;
	Data.result.pos.y = 200;
	strcpy_s(Data.result.str, "＜RESULT＞");
	//プレイヤー
	//move
	Data.player.angle = 0;
	Data.player.angSpeed = 120;
	Data.player.advSpeed = 5;
	Data.player.pos.x = width/2;
	Data.player.pos.y = height/2;
	Data.player.limmitW = 100;


	
}
void CONTAINER::loadGraphic() {
	Data.title.titleImg = loadImage("assets\\Title.png");
	Data.select.selectImg = loadImage("assets\\Select.png");
	Data.player.img = loadImage("assets\\player_demo.png");
	Data.back.backImg = loadImage("assets\\stage1.png");
}