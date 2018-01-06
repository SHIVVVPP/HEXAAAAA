#pragma once
#include "enemy.h"
class bubble : public enemy
{
public:
	bubble();
	~bubble();

	HRESULT init(MONSTER_INDEX mon_index, POINT leftX_topY);
	void frameMove();

	void Move();
};

