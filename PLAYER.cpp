#include "PLAYER.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "PLAYER_VEC.h"
#include "PLAYER_BULLET.h"
#include "ENEMYS.h"
#include "libOne.h"

PLAYER::PLAYER(GAME* game):
	GAME_OBJECT(game) {
}
void PLAYER::create()
{
	Player = game()->container()->player();
}
void PLAYER::init()
{
	Player.pos = game()->container()->player().pos;
}
void PLAYER::update()
{
	move();
	launch();
}
void PLAYER::move(){
	
	struct VEC a, b;
		
	if (Player.pos.x < width - Player.limmitX && isPress(KEY_D))b.x = 1;
	if (Player.pos.x > Player.limmitX && isPress(KEY_A))b.x = -1;
	if (Player.pos.y > Player.limmitY && isPress(KEY_W))b.y = -1;
	if (Player.pos.y < height - Player.limmitY && isPress(KEY_S))b.y = 1;
	if (b.x != 0 || b.y != 0) {		

		
		//プレイヤーの移動
		b = normalize(&b);//速度の均等化
		Player.pos.x += b.x * Player.advSpeed;
		Player.pos.y += b.y * Player.advSpeed;
		
		//プレイヤーの回転
		a = vecFromAngle(Player.angle);
		Player.angSpeed = angleBetweenTwoVecs(&a, &b) / 4;
		Player.angle += Player.angSpeed;

	}
}
void PLAYER::launch(){

	if (isPress(KEY_SPACE)) {
		Player.triggerErapsedTime += delta;
		if (Player.triggerErapsedTime >= Player.triggerIntreval) {
			VECTOR2 pos = Player.pos + Player.launchVec * Player.ofstLaunchDist;
			game()->playerBullet()->launch(pos, Player.launchVec);
			Player.triggerErapsedTime = 0;
		}
	}
	else {
		Player.triggerErapsedTime = Player.triggerIntreval;
	}

}
void PLAYER::collision(){
	if (Player.invincibleRestTime > 0) {
		Player.invincibleRestTime -= delta;
	}
	else {
		Player.color = Player.normalColor;
		ENEMYS* enemy = game()->enemies();
		float distance = Player.bcRadius + game()->enemies()->bcRadius();
		float sqDistance = distance * distance;
		for (int i = enemy->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Player.pos - enemy->pos(i);
			if (sqLength(vec) < sqDistance) {
				Player.hp--;
				Player.invincibleRestTime = Player.invincibleTime;
				Player.color = Player.collisionColor;
				imageColor(Player.collisionColor);
				enemy->kill(i);
				i = 0;
			}
		}
	}

}
void PLAYER::draw()
{
	rectMode(CENTER);
	image(Player.img, Player.pos.x, Player.pos.y, Player.angle);
	if (isTrigger(KEY_Z)) {
		Player.pos.x = width / 2;
		Player.pos.y = height / 2;
		Player.angle = 0;
	}

}

void PLAYER::updateForGameOver()
{
}

