#pragma once
#include "NPC.h"

class Crown :
	public NPC
{
public:
	Crown();
	~Crown();

	virtual void Converstion(int tolkCount);
};

