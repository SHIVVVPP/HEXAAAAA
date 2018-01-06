#pragma once
#include "objects.h"
class fakedirt : public objects
{
public:
	HRESULT init(int x, int y , int width);
	void update();
	void render();
	fakedirt();
	~fakedirt();
};

