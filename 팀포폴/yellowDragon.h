#pragma once
#include "enemy.h"
class yellowDragon : public enemy
{
public:
	yellowDragon();
	~yellowDragon();

	HRESULT init(MONSTER_INDEX mon_index, POINT leftX_topY);
	void frameMove();
};
