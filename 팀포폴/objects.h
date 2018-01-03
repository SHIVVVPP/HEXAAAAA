#pragma once
#include "gameNode.h"

#define TYPE_LADDER 0
#define TYPE_GEM 1
#define TYPE_FOOD 2
#define TYPE_PLATTER 3
#define TYPE_DIRTPILE 4
#define TYPE_BLOCK 5
#define TYPE_MOVING_BLOCK 6
#define TYPE_SKULL 7
class objects : public gameNode
{
private:
	int _type;
	RECT _rc;

	bool _move;
	bool _hang;

	bool _picked;

public:
	objects();
	~objects();

	virtual HRESULT init(int x, int y);	
	virtual	HRESULT init(int x, int y, int length);
	virtual HRESULT init(int x, int y, float angle);
	virtual void update();
	virtual void render();
	virtual void release();
	virtual void move();
};

