#pragma once
#include "gameNode.h"

enum TYPE_ITEMS
{
	OBJECT,
	MONSTER,
};

#define		fakehead_left 0
#define 	fakehead_right 1
#define 	fakeline_left 2
#define 	fakeline_right 3
#define 	faketail_left 4
#define 	faketail_right 5
#define 	goldplatter 6
#define 	platter 7
#define 	moving_block 8


#define 노란드래곤 0
#define 레드비틀 1
#define 스켈레톤 2
#define 슬라임 3
#define 초록용 4

class settingTool : public gameNode
{
private:

	TYPE_ITEMS TYPE;
	int detail;
	RECT _rc;
	image* _image;


public:
	settingTool();
	~settingTool();

	HRESULT init();
	void release();
	void update();
	void render();
};

