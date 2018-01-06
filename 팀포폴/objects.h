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
#define TYPE_SMALL_BLOCK 10


class objects : public gameNode
{
	friend class objectManager;
protected:
	animation* _objAni;
	int _type;
	RECT _rc;
	bool _move;
	bool _hang;
	bool _canHit;
	bool _picked;
	bool _canLand;
	int _leftX;
	int _topY;
	int _startX, _startY;
	int _range;
	int _width, _height;
	int _goldValue;
	int _helathValue;
	int _manaValue;
	int _alphaValue;
	float _speedX;
	float _angle;
	const char* _imageName;
	image* _image;
	int _shuf;
public:
	objects();
	~objects();
	virtual HRESULT init(int x, int y, int range, bool isRight);
	virtual HRESULT init(int x, int y, int startX, int startY);
	virtual HRESULT init(int x, int y);	
	virtual	HRESULT init(int x, int y, float length);
	virtual HRESULT init(int range  ,int x, int y, int startX, int startY, float speed, float angle);
	virtual HRESULT init(int x, int y, int value);
	virtual void update();
	virtual void render();
	virtual void release();
	virtual void move();
	
	animation* getAni() { return _objAni; }
	int getX() { return _leftX; }
	int getY() { return _topY; }
	RECT getRc() { return _rc; }
	void setRC(RECT rc) { _rc = rc; }
	const char* getImage() { return _imageName; }
};

