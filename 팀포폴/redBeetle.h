#pragma once
#include "enemy.h"

class redBeetle : public enemy
{

public:
	redBeetle();
	~redBeetle();

	HRESULT init(MONSTER_INDEX mon_index, POINT leftX_topY);
	void release();
	void update();
	void render();

	void CollisionReact();

	void setMainCondition(MONSTER_MAINCONDITION mainCondition);
	void setSubCondition(MONSTER_SUBCONDITION subCondition);
	void setCondition();
};

