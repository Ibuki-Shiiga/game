#include "ENEMYS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
#include"PLAYER_BULLET.h"
#include <corecrt_math.h>
//#include"HP_GAUGE.h"
ENEMYS::ENEMYS(class GAME* game) :
	GAME_OBJECT(game) {
}
ENEMYS::~ENEMYS() {
	delete[] Enemies;
}
void ENEMYS::create() {
	Enemy = game()->container()->enemy();
	Enemies = new ENEMY[Enemy.totalNum];
}
void ENEMYS::init() {
	Enemy.centerPos = game()->container()->enemy().centerPos;
	
	float divTheta = 3.1415926f * 2 / Enemy.totalNum;
	float divInterval = Enemy.triggerInterval / Enemy.totalNum;
	for (int i = 0; i < Enemy.totalNum; i++) {
		Enemies[i].ofstTheta = divTheta * i;
		Enemies[i].triggerErapsedTime = divInterval * i;
		Enemies[i].triggerErapsedTime = 0;
		Enemies[i].hp = Enemy.initHp;
	}
	

	Enemy.curNum = Enemy.totalNum;
}
void ENEMYS::update() {
	move();
	collision();
}
void ENEMYS::move() {
	if (Enemy.centerPos.y < Enemy.targetPosY) {
		Enemy.centerPos.y += Enemy.fallSpeed * delta;
	}
	for (int i = 0; i < Enemy.curNum; i++) {
		float theta = Enemy.refTheta + Enemies[i].ofstTheta;
		float px = Enemy.centerPos.x + cos(theta) * Enemy.majRadius;
		float py = Enemy.centerPos.y + sin(theta) * Enemy.minRadius;
		VECTOR2 playerPos = game()->player()->pos();

		VECTOR2 launchVec = normalize(playerPos - Enemies[i].pos);
		VECTOR2 pos = Enemies[i].pos + launchVec * Enemy.ofstLaunchDist;

		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;
	}
	Enemy.refTheta += Enemy.thetaSpeed * delta;
}
void ENEMYS::launch() {
	VECTOR2 playerPos = game()->player()->pos();
	for (int i = 0; i < Enemy.curNum; i++) {
		Enemies[i].triggerErapsedTime += delta;
		if (Enemies[i].triggerErapsedTime >= Enemy.triggerInterval) {
			VECTOR2 launchVec = normalize(playerPos - Enemies[i].pos);
			VECTOR2 pos = Enemies[i].pos + launchVec * Enemy.ofstLaunchDist;
			Enemies[i].triggerErapsedTime = 0;
		}
	}
}
void ENEMYS::collision() {
	BULLETS* bullets = game()->playerBullet();
	float distance = Enemy.bcRadius;
	float sqDistance = distance * distance;
	for (int j = Enemy.curNum - 1; j >= 0; j--) {
		if (Enemies[j].invincibleRestTime > 0) {
			Enemies[j].invincibleRestTime -= delta;
		}
		else {
			Enemies[j].color = Enemy.normalColor;
			for (int i = bullets->curNum() - 1; i >= 0; i--) {
				VECTOR2 vec = Enemies[j].pos - bullets->pos(i);
				
				if (sqLength(vec) < sqDistance) {
					Enemies[j].hp--;
					Enemies[j].invincibleRestTime = Enemy.invincibleTime;
					Enemies[j].color = Enemy.collisionColor;
					if (Enemies[j].hp <= 0) {
						Enemy.curNum--;
						Enemies[j] = Enemies[Enemy.curNum];
					}

					kill(i);
					i = 0;
				}
				
			}
		}
	}
}
void ENEMYS::draw() {
	for (int i = 0; i < Enemy.curNum; i++) {
		imageColor(Enemies[i].color);
		image(Enemy.img, Enemies[i].pos.x, Enemies[i].pos.y);
		//game()->hpGauge()->draw(Enemies[i].pos, Enemy.hpGaugeOfst,
			//Enemies[i].hp);
	}
}

void ENEMYS::kill(int i)
{
	Enemy.curNum--;
	Enemies[i] = Enemies[Enemy.curNum];
}