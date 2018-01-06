#pragma once
#include "objects.h"
class platter : public objects
{
public:
	platter();
	~platter();

	HRESULT init(int x, int y , float length);
	void update();
	void render();
};


