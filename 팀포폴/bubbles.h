#pragma once
#include "objects.h"
class bubbles : public objects
{
public:
	HRESULT init(int x , int y, int startX, int startY , int range);
	void update();
	void render();
	void move();
	bubbles();
	~bubbles();
};

