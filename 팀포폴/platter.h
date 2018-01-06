#pragma once
#include "objects.h"
class platters : public objects
{
public:
	platters();
	~platters();

	HRESULT init(int x, int y);
	void update();
	void render();
};


