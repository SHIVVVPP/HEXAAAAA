#pragma once
#include "gameNode.h"

enum MONSTER_INDEX 
{
	MON_REDBITTLE,
	MON_GREENDRAGON,
	MON_SLIME,
	MON_SKELETON,
	MON_YELLOWDRAGON,
	MON_BUBBLE,
	MON_BOSS,
};

enum monsterDirection
{
	leftStand,
	rightStand,
	leftMove,
	rightMove,
	leftDead ,
	rightDead ,
	leftAttack,
	rightAttack,
	leftBackStep,
	rightBackStep,
	leftSpawn ,
	rightSpawn ,
	rightJump ,
	leftJump ,
	rightJumpAttack ,
	leftJumpAttack ,
	rightRangeAttack ,
	leftRangeAttack ,
	rightDamaged ,
	leftDamaged 
};

class enemy : public gameNode
{
protected:


	MONSTER_INDEX _index;
	image* _imageName;
	RECT _rc;
	RECT _collisionRc;
	RECT _subCollisionRc;
	RECT _detectRc;
	RECT _attackRc;
	int _hitCounter;			//히트카운터 맞을횟수
	int centerX, centerY;		//좌표 x, y
	int _rcX, _rcY;				//충돌렉트 크기
	int _subRcX, _subRcY;		//서브충돌렉트 크기
	int _rcPlaceX, _rcPlaceY, _subRcPlaceX, _subRcPlaceY; //충돌렉트와 서브충돌렉트 좌표 수정
	float reflectJumpPower;
	float _jumpPower;
	float _gravity;
	float _speed;

	int frameCounter;
	int slowFrameCounter;
	int _currentFrameX, _currentFrameY;

	int _probeX;
	int _probeY;

	animation* _monsterMotion;

	int _monsterDirection;

	bool _attackChance;


public:

	virtual HRESULT init(MONSTER_INDEX mon_index,POINT leftX_topY);
	/*	virtual HRESULT init(const char* imageName, POINT position, int hitCounter, int rcX, int rcY, int rcPlaceX, int rcPlaceY);


	virtual HRESULT init(const char* imageName, POINT position, int hitCounter, int rcX, int rcY, int rcPlaceX,
		int rcPlaceY, int subRcX, int subRcY, int subRcPlaceX, int subRcPlaceY);
		*/
	virtual void release();
	virtual void update();
	virtual void render();

	//void aniSheet();
	void generalMove();					
	void damaged();						//맞았을때 함수


	virtual void frameMove() {}
	virtual void move(){}

	/*
	void slimeFameMove();				//몬스터별 프레임 무브
	void redbeetleFrameMove();
	void greenDragonFrameMove();
	void yellowDragonFrameMove();
	void skeletonFrameMove();
	void bossFrameMove();

	void bubbleFrameMove();
	void bubbleMove();
	*/


//	void detecting();



	//void beetleAni();
	//void slimeAni();
	//void greenDragonAni();
	//void skeletonAni();
	//void yellowDragonAni();

	inline int getCenterX() { return centerX; }
	inline int getCenterY() { return centerY; }

	inline int getFrameX() { return _currentFrameX; }				//x프레임 접근자
	inline int getFrameY() { return _currentFrameY; }				//y프레임 접근자

	inline int getJumpPower() { return _jumpPower; }
	inline int getGravity() {return _gravity;}

	inline int getHitCounter() { return _hitCounter; }				//맞은횟수 히트카운터 접근자
	inline RECT getCollsionRect() { return _collisionRc; }            //몬스터 충돌rc 접근자
	inline RECT getSubCollsionRect() { return _subCollisionRc; }	  //몬스터 서브 충돌rc 접근자	
	inline RECT getAttackRect() { return _attackRc; }
	inline RECT getDetectRect() { return _detectRc; }

	inline float getCounterJumpPower() { return reflectJumpPower; }   //몬스터 점프 아래 공격시 플레이어가 가지는 점프파워
	inline int getMonsetrDirection() { return _monsterDirection; }	  //몬스터 상태 접근자
//	void* getMotion() { return _monsterMotion; }



	enemy();
	~enemy();
};



