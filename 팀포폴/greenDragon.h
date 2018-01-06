#pragma once
#include "enemy.h"

class greenDragon : public enemy
{
public:
	greenDragon();
	~greenDragon();

	HRESULT init(MONSTER_INDEX mon_index, POINT leftX_topY);
	void frameMove();
};

