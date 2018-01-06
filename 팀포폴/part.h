#pragma once
#include "objects.h"
class part :public objects
{
public:

	HRESULT init(int x, int y);
	void update();
	void render();
	void move();
	part();
	~part();
};

