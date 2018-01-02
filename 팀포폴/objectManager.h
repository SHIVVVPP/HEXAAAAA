#pragma once
#include "gameNode.h"

class objectManager : public gameNode
{

private

	RECT _challengeGoal;
	RECT _dirtblock;
	RECT _dirtblock_small;
	RECT _dirtpile1;
	RECT _dirtpile2;
	RECT _dirtpile3;
	RECT _dirtpile4;
	RECT _dirtpile5;
	RECT _bubble;
	RECT _digClod1;
	RECT _digClod2;
	RECT _fakeblack1;
	RECT _fakeblack2;

	RECT _blueBump;
	RECT _yellowBump;
	RECT _radBump;

	animation* blueBump_hit;
	animation* yellowBump_hit;
	animation* radBump_hit;

	animation* _dirtblock_effect;
    animation* _dirtblock_small_effect;
    animation* _challengeGoal_effect;

 
public:
	objectManager();
	~objectManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

