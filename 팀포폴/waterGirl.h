#pragma once
#include "NPC.h"
class waterGirl :
	public NPC
{
private:
	int count = 0;
	RECT RC;
public:
	waterGirl();
	~waterGirl();
	virtual void Move();
	virtual void render();

	RECT getRC() { return RC; }
	
};

