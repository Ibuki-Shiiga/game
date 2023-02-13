#include "BACK.h"
#include "CONTAINER.h"
#include "GAME.h"
#include "libOne.h"

BACK::BACK(GAME* game):
  GAME_OBJECT(game){
}

void BACK::create(){
	Back = game()->container()->back();
}

void BACK::draw(){
	image(Back.backImg, Back.backX, Back.backY);
	rectMode(CENTER);

}
