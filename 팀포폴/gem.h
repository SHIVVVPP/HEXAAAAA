#pragma once
#include "objects.h"

class gem : public objects
{
public:
	HRESULT init(const char* imageName, int goldup);
	void update();
	void render();
	void fire(int x, int y,int startX,int startY, float speed, float angle);
	void move();
	gem();
	~gem();
};

