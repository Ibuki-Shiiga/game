#include "CONTAINER.h"
void CONTAINER::load() {
	setData();
}
void CONTAINER::setData() {
	//�^�C�g��
	Data.title.backColor = COLOR(0,20,0);
	Data.title.textColor = COLOR(0,255,255);
	Data.title.textSize = 400;
	Data.title.pos.x = 400;
	Data.title.pos.y = 700;
	strcpy_s(Data.title.str, "TITLE");
}