#pragma once
#include "enemy.h"
class skeleton : public enemy
{
public:
	skeleton();
	~skeleton();

	HRESULT init(MONSTER_INDEX mon_index, POINT leftX_topY);
	void frameMove();
};

