#pragma once
#include "objects.h"

class gem : public objects
{
public:
	HRESULT init(const char* imageName, int goldup, bool hit);
	void update();
	void render();
	void fire(int x, int y, float speed, float angle);
	void move();
	gem();
	~gem();
};

