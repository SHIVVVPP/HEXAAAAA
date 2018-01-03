#pragma once
#include "gameNode.h"


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


	image* _imageName;
	RECT _rc;
	RECT _collisionRc;
	RECT _subCollisionRc;
	RECT _detectRc;
	RECT _attackRc;
	int _hitCounter;			//��Ʈī���� ����Ƚ��
	int centerX, centerY;		//��ǥ x, y
	int _rcX, _rcY;				//�浹��Ʈ ũ��
	int _subRcX, _subRcY;		//�����浹��Ʈ ũ��
	int _rcPlaceX, _rcPlaceY, _subRcPlaceX, _subRcPlaceY; //�浹��Ʈ�� �����浹��Ʈ ��ǥ ����
	float reflectJumpPower;

	int frameCounter;
	int slowFrameCounter;
	int _index = 0;
	int _currentFrameX, _currentFrameY;

	int _probeX;
	int _probeY;

	animation* _monsterMotion;

	int _monsterDirection;

	bool _attackChance;


public:

	virtual HRESULT init();
	HRESULT init(const char* imageName, POINT position, int hitCounter, int rcX, int rcY, int rcPlaceX, int rcPlaceY);

	HRESULT init(const char* imageName, POINT position, int hitCounter, int rcX, int rcY, int rcPlaceX,
		int rcPlaceY, int subRcX, int subRcY, int subRcPlaceX, int subRcPlaceY);

	virtual void release();
	virtual void update();
	virtual void render();

	//void aniSheet();
	void generalMove();					
	void damaged();						//�¾����� �Լ�

	void slimeFameMove();				//���ͺ� ������ ����
	void redbeetleFrameMove();
	void greenDragonFrameMove();
	void yellowDragonFrameMove();
	void skeletonFrameMove();
	void bossFrameMove();
	void detecting();



	//void beetleAni();
	//void slimeAni();
	//void greenDragonAni();
	//void skeletonAni();
	//void yellowDragonAni();

	inline int getCenterX() { return centerX; }
	inline int getCenterY() { return centerY; }

	inline int getFrameX() { return _currentFrameX; }				//x������ ������
	inline int getFrameY() { return _currentFrameY; }				//y������ ������

	inline int getHitCounter() { return _hitCounter; }				//����Ƚ�� ��Ʈī���� ������
	inline RECT getCollsionRect() { return _collisionRc; }            //���� �浹rc ������
	inline RECT getSubCollsionRect() { return _subCollisionRc; }	  //���� ���� �浹rc ������	
	inline RECT getAttackRect() { return _attackRc; }
	inline RECT getDetectRect() { return _detectRc; }

	inline float getCounterJumpPower() { return reflectJumpPower; }   //���� ���� �Ʒ� ���ݽ� �÷��̾ ������ �����Ŀ�
	inline int getMonsetrDirection() { return _monsterDirection; }	  //���� ���� ������
//	void* getMotion() { return _monsterMotion; }



	enemy();
	~enemy();
};



