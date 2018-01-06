#pragma once
#include "objects.h"

class gem : public objects
{
public:
	HRESULT init(int range  ,int x, int y, int startX, int startY, float speed, float angle);
	
	void update();
	void render();
	
	void move();
	gem();
	~gem();
};

