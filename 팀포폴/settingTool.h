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


#define ����巡�� 0
#define �����Ʋ 1
#define ���̷��� 2
#define ������ 3
#define �ʷϿ� 4

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

