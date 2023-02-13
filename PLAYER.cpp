#include "PLAYER.h"
#include "CONTAINER.h"
#include "PLAYER_VEC.h"
#include "GAME.h"
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
}
void PLAYER::move(){
	
	if (Player.pos.x > Player.limmitW && isPress(KEY_A)) {
		Player.pos.x += -Player.advSpeed * delta;
		
	}
	else if (Player.pos.x < width - Player.limmitW && 
		isPress(KEY_D)) {
		Player.pos.x += Player.advSpeed * delta;

	}
	if (Player.pos.y> Player.limmitW && isPress(KEY_W)) {
		Player.pos.y += -Player.advSpeed * delta;

	}
	else if (Player.pos.y < height - Player.limmitW &&
		isPress(KEY_S)) {
		Player.pos.y += Player.advSpeed * delta;

	}
	
	struct VEC a, b;
	if (isPress(KEY_D))b.x = 1;
	if (isPress(KEY_A))b.x = -1;
	if (isPress(KEY_W))b.y = -1;
	if (isPress(KEY_S))b.y = 1;
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
void PLAYER::launch(){}
void PLAYER::collision(){}
void PLAYER::draw()
{
	rectMode(CENTER);
	image(Player.img, Player.pos.x, Player.pos.y, Player.angle);
}

