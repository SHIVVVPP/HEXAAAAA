#pragma once
#include "NPC.h"
class deerLady :
	public NPC
{
private:
	int count = 0;
	bool visible = true;
public:
	deerLady();
	~deerLady();
	virtual void Move();
	virtual void render();
};

