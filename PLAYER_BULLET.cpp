#include "CONTAINER.h"
#include "GAME.h"
#include "PLAYER_VEC.h"
#include "PLAYER_BULLET.h"

PLAYER_BULLET::PLAYER_BULLET(GAME* game):
	BULLETS(game){
}

void PLAYER_BULLET::create()
{
	SetBullets(game()->container()->playerBullet());
}
void PLAYER_BULLET::angle() {
	

}
