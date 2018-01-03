#pragma once
#include "gameNode.h"

#define TYPE_LADDER 0
#define TYPE_GEM 1
#define TYPE_FOOD 2
#define TYPE_PLATTER 3
#define TYPE_DIRTPILE 4
#define TYPE_BLOCK 5
#define TYPE_MOVING_BLOCK 6
#define TYPE_POTION 7
#define TYPE_BARRIER 8
#define TYPE_MEAL 9
class objects : public gameNode
{
protected:
	animation* _objAni;
	int _type;
	RECT _rc;

	bool _move;
	bool _hang;

	bool _picked;
	bool _canLand;
	int _x;
	int _y;
	int _startX, _startY;
	int _range;
	int _width, _height;
	int _goldValue;
	float _speedX;
	const char* _imageName;
public:
	objects();
	~objects();
	virtual HRESULT init(int x, int y, int range, bool isRight);
	virtual HRESULT init(int x, int y, int startX, int startY);
	virtual HRESULT init(int x, int y);	
	virtual	HRESULT init(int x, int y, float length);
	virtual HRESULT init(int x, int y, const char* imageName , int goldup);
	virtual void update();
	virtual void render();
	virtual void release();
	virtual void move();
	animation* getAni() { return _objAni; }
	int getX() { return _x; }
	int getY() { return _y; }
};

