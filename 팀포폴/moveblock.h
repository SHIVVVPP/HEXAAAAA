#pragma once
#include "objects.h"
class moveblock : public objects
{
public:
	moveblock();
	~moveblock();

	HRESULT init(int x, int y,int range,bool isRight,bool isUp , bool type);
	void update();
	void render();
};

