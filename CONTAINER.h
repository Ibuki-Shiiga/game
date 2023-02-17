#pragma once
#include "TITLE.h"
#include "SELECT.h"
#include "RESULT.h"
#include "BACK.h"
#include "PLAYER.h"
#include "ENEMYS.h"
#include "BULLETS.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		SELECT::DATA select;
		RESULT::DATA result;
		ENEMYS::DATA enemy;
		BACK::DATA back;
		PLAYER::DATA player;
		BULLETS::DATA playerBullet;


	};
	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();

	const TITLE::DATA& title() { return Data.title; }
	const SELECT::DATA& select() { return Data.select; }
	const RESULT::DATA& result() { return Data.result; }
	const ENEMYS::DATA& enemy() { return Data.enemy; }
	const BACK::DATA& back() { return Data.back; }
	const PLAYER::DATA& player() { return Data.player; }
	const BULLETS::DATA& playerBullet() { return Data.playerBullet; }

};

