#pragma once
#include "objects.h"
class ladder :public objects
{
public:
	ladder();
	~ladder();

	HRESULT init(int x, int y, float length);
	void render();
};

