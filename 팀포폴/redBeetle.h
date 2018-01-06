#pragma once
#include "enemy.h"

class redBeetle : public enemy
{

public:
	redBeetle();
	~redBeetle();

	HRESULT init(MONSTER_INDEX mon_index, POINT leftX_topY);
	void frameMove();
};

