#pragma once
#include "enemy.h"

class blueSlime : public enemy
{
public:
	blueSlime();
	~blueSlime();

	HRESULT init(MONSTER_INDEX mon_index, POINT leftX_topY);
	void frameMove();
};
