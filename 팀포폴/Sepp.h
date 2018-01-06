#pragma once
#include "NPC.h"
class Sepp :
	public NPC
{
private:
	int count =0;
	bool isCooking = false;
public:
	Sepp();
	~Sepp();
	virtual void render();
	virtual void aniMove();
	virtual void tolkdrow();
	virtual void Converstion(int tolkCount);

};

