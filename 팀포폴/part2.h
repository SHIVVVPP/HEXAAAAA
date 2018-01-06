#pragma once
#include "objects.h"
class part2 : public objects
{
public:

	HRESULT init(int x, int y);
	void update();
	void render();
	void move();
	part2();
	~part2();
};

