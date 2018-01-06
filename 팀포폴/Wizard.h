#pragma once
#include "NPC.h"
class Wizard :
	public NPC
{
public:
	Wizard();
	~Wizard();
	virtual void tolkdrow();
	virtual void Converstion(int tolkCount);
};

