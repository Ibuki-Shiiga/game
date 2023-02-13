#pragma once
#include "TITLE.h"
#include "SELECT.h"
#include "RESULT.h"
#include "STAGE01.h"
#include "PLAYER.h"
#include "BACK.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		SELECT::DATA select;
		RESULT::DATA result;
		//STAGE01::DATA stage01;

		PLAYER::DATA player;
		BACK::DATA back;
	};
	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();

	const TITLE::DATA& title() { return Data.title; }
	const SELECT::DATA& select() { return Data.select; }
	const RESULT::DATA& result() { return Data.result; }
	//const STAGE01::DATA& stage01() { return Data.stage01; }

	const PLAYER::DATA& player() { return Data.player; }
	const BACK::DATA& back() { return Data.back; }
};

