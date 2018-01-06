#pragma once
#include "enemy.h"

class boss : public enemy
{
public:
	boss();
	~boss();

	HRESULT init(MONSTER_INDEX mon_index, POINT leftX_topY);
	void frameMove();
};

