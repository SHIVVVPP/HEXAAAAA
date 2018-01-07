#pragma once
#include "gameNode.h"
#include "animation.h"

enum MONSTER_INDEX 
{
	MON_REDBITTLE,
	MON_SKELETON,
	MON_YELLOWDRAGON,
	MON_BOSS,
};



//기본 상태값
enum MONSTER_MAINCONDITION
{
	STAND,
	MOVE,
	BACKMOVE,
	HITTED,
	DIE,
};

enum MONSTER_SUBCONDITION
{
	LAND,
	JUMP,
	ATTACK,
	FALL,
};

enum MON_PATTERN
{
	NONE_PATTERN,
	STAND_ATTACK,
	MOVE_ATTACK,
	JUMP_ATTACK,
};

class enemy : public gameNode
{
protected:


	MONSTER_INDEX _index;
	animation* _ani;
	image* _image;
	RECT _imageRc;
	RECT _collisionRc; //_collisionRc -> 몬스터 실제 size

	RECT* _playerC;

	int _attackCount;
	
	//image 기준 
	int _leftX, _topY;

	//충돌렉트 기준
	int _width, _height;

	int _hp;

	bool _detect;
	bool _isRight;
	int _speedX;
	float _sumGravity;
	float _sumNuckBack;
	POINT _range;

	MON_PATTERN _pattern;
	MONSTER_MAINCONDITION _mainCondition;
	MONSTER_SUBCONDITION _subCondition;
	


public:

	virtual HRESULT init(MONSTER_INDEX mon_index,POINT leftX_topY);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void changeDirection();
	virtual void changeDirection(bool state);
	void pixelCollisionReact(image* collisionImage, POINT ptReal);
	virtual void move() {}
	
	virtual void CollisionReact() {}


	//업뎃
	virtual void setMainCondition(MONSTER_MAINCONDITION mainCondition) {}
	virtual void setSubCondition(MONSTER_SUBCONDITION subCondition) {}
	virtual void setCondition() {}

	

	virtual void chagePattern(MON_PATTERN pattern) {}



	void setPlayerRc(RECT* pRC) { _playerC = pRC; }

	enemy();
	~enemy();
};



