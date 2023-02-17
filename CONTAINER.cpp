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
	//strcpy_s(Data.select.str, "＜メニュー＞"); 
	//Data.select.pos.x = 100;
	//Data.select.pos.y = 300;
	Data.select.textColor = COLOR(255, 255, 255);
	Data.select.textSize = 120;

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
	Data.back.backPos.x = width/2;
	Data.back.backPos.y = height/2;
	//Data.stage01.Stage1pos.x = width / 2;
	//Data.stage01.Stage1pos.y = height / 2;

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
	Data.player.advSpeed = 3;
	Data.player.pos.x = width/2;
	Data.player.pos.y = height/2;
	Data.player.limmitX = 500;
	Data.player.limmitY = 80;
	//launch
	Data.player.launchVec = VECTOR2(0,-1);
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerIntreval = 0.1f;
	Data.player.ofstLaunchDist = 10;
	Data.player.lunchAngSpeed = 0;
	Data.player.lunchAngle = 0;
	//collosion
	Data.player.bcRadius = 40;
	Data.player.invincibleTime = 0;
	Data.player.invincibleRestTime = 0;
	Data.player.hp = 5;
	Data.player.hpGaugeOfst = VECTOR2(0, -120);
	Data.player.collisionColor = COLOR(255,0,0);
	Data.player.normalColor = COLOR(255,255,255);

	
	
	//エネミー１
	
	Data.enemy.totalNum = 100;
	Data.enemy.curNum = 100;// Data.enemy.totalNum;
	Data.enemy.majRadius = 700;
	Data.enemy.minRadius = 100;
	Data.enemy.centerPos = VECTOR2(960, 300);
	Data.enemy.fallSpeed = 200;
	Data.enemy.targetPosY = 200;
	Data.enemy.refTheta = 69;
	Data.enemy.thetaSpeed = 0.6f;
	Data.enemy.triggerInterval = 0.72f;
	Data.enemy.ofstLaunchDist = 100;
	//collision
	Data.enemy.bcRadius = 20;
	Data.enemy.invincibleTime = 0.05f;
	Data.enemy.initHp = 5;
	Data.enemy.hpGaugeOfst = VECTOR2(0, 120);
	Data.enemy.collisionColor = COLOR(255, 0, 0);
	Data.enemy.normalColor = COLOR(255, 255, 255);
	Data.enemy.advSpeed = 400;
	Data.enemy.angSpeed = 5.0f;
	


	//PLAYER_BULLET
	Data.playerBullet.totalNum = 20;
	Data.playerBullet.curNum = 0;
	Data.playerBullet.advSpeed = 1000;
	Data.playerBullet.angSpeed = Data.player.angle;
	Data.playerBullet.bcRadius = 20;

	
}
void CONTAINER::loadGraphic() {
	Data.title.titleImg = loadImage("assets\\Title.png");
	Data.select.selectImg = loadImage("assets\\Menew_b.png");
	Data.back.backImg = loadImage("assets\\stage1.png");
	Data.player.img = loadImage("assets\\player_demo.png");
	Data.enemy.img = loadImage("assets\\EnemysU.png");
	Data.playerBullet.img = loadImage("assets\\RedShot.png");

}