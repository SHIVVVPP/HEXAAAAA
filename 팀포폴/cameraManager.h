#pragma once
#include "singletonBase.h"
#include <vector>

//stdafx.h��  BACKGROUNDSIZEX,Y DEFINE�߰� CAMERAMANAGER DEFINE �߰� GAMENODE�� CAMERAMANAGER INIT() UPDATE()

#define CAMERA_VERTICAL 0
#define CAMERA_HORIZONTAL 1

//ī�޶� ���°� ���� ����
#define CAMERA_FREE 0 //ī�޶� �����Ӱ� �̵��� �� ����
#define CAMERA_AIMING 1 //ī�޶� aim ���� ������ rc�� ����
#define CAMERA_EFFECT 2 //ī�޶� ��鸲, ȿ�� ó��
#define CAMERA_MOVING 3 //ī�޶� �̵�ó��

//ī�޶� ������Ʈ Ÿ��
#define C_OBJECT_MOVE 0
#define C_OBJECT_MOVE2 1

//������Ʈ �浹 Ÿ��
#define C_OBJECT_TO_NEXT 0
#define C_OBJECT_TO_PRE 1


//����Ʈ
//#define EFFECT_POWF 0
#define EFFECT_SIN 1
//#define EFFECT_SINPOWF 2
//#define EFFECT_SINPOWF2 3



typedef struct tagCameraObject
{
	RECT _rc;
	int _type;
	int prevCondition, nextCondition;
	float progressX;
	float progressY;
	bool isVertical;
	bool sence_vertical;
	bool left_top;
	POINT nextCameraLimit;
	POINT prevCameraLimit;
	RECT* _aim;
	bool moveFinish;
	bool toNext;
	int prevP;

	//����������
	string nextRoom,prevRoom;


	tagCameraObject()
	{
		prevCondition = _type = nextCondition = 0;
		progressX = 0;
		progressY = 0;
		nextCameraLimit = { 0,0 };
		prevCameraLimit = { 0,0 };
		moveFinish = false;
		_aim = NULL;
	}
	

}CAMERA_OBJECT;


class cameraManager : public singletonBase<cameraManager>
{
private:
	typedef vector<CAMERA_OBJECT> vCO;
	typedef vector<CAMERA_OBJECT>::iterator viCO;

private:
	vCO _vO;
	CAMERA_OBJECT* _currentO_X;
	CAMERA_OBJECT* _currentO_Y;
	

	int BACKGROUND_START_X, BACKGROUND_START_Y;
	int BACKGROUND_LIMIT_X, BACKGROUND_LIMIT_Y;

	RECT* _aim;

	POINT _camera;

	int _cameraConditionX, _cameraConditionY;
	int _prevCameraConditionX, _prevCameraConditionY;

	int _effectIndex;
	float originX, originY;
	float _strongX, _strongY;
	float _effectT_X, _effectT_Y, _maxEffectT_X, _maxEffectT_Y;


	//move
	int _destX, _destY;
	float _speedX, _speedY;
	bool finishX, finishY;

public:
	cameraManager();
	~cameraManager();

	HRESULT init(void);
	void release(void);
	void update(void);

	POINT getBackground() { return { BACKGROUND_LIMIT_X,BACKGROUND_LIMIT_Y }; }
	void setBackground(int x, int y) { BACKGROUND_LIMIT_X = x; BACKGROUND_LIMIT_Y = y; }
	void setStartBackground(int x, int y) { BACKGROUND_START_X = x; BACKGROUND_START_Y = y; }
	// �ش��ϴ� rc�� ī�޶� �����մϴ�.
	void setCameraAim(RECT* rc);

	// object�� ī�޶� ȭ�� ���ʿ� �ִ��� �˾Ƴ��ϴ�.
	bool isInCamera(RECT rc);

	void cameraMoveTo(bool vertical, int dest,float speed);

	void cameraFollow(bool vertical);


	// CAMERA_FREE, CAMERA_AIMING, CAMERA_EFFEICTING, CAMERA_MOVING�� ī�޶� ���¸� �����մϴ�.
	inline	void setCameraCondition(bool vertical,int cameraCondition) {if(vertical) _cameraConditionY = cameraCondition; else _cameraConditionX = cameraCondition;
	}

	//ī�޶� ȭ��� ��ǥ�� ��ȯ�մϴ�.
	inline POINT CameraRelativePoint(RECT rc) { return { rc.left - _camera.x, rc.top - _camera.y }; }
	inline int CameraRelativePointX(int x) { return  x - _camera.x; }
	inline int CameraRelativePointY(int y) { return y - _camera.y; }

	//ī�޶� ��ġ�� ����� �����Ѵ�.
	inline void cameraRevision();

	// ī�޶� ����Ʈ ���� EFFECT_SIN,..., ����, �ð�(��)
	inline void setEffect(int effectIndex, float strong, float time);

	//ī�޶� ������
	inline void cameraEffecting(bool vertical);

	inline int getCameraCondition() { return _cameraConditionX; }

	inline POINT getCameraPoint() { return _camera; }

	//ī�޶� ������Ʈ



	/*RECT _rc;
	int prevCondition, inCondition, nextCondition;
	float progress;
	tagRect nextCameraLimit;
	tagRect prevCameraLimit;
	RECT* _aim;*/
	void  addCameraObject(bool vertical,bool senceside,int objectType, int nextCameraCondition, RECT rc, POINT prevLimit, POINT nextLimit, RECT* aim, bool left_top,string connectN);
	void cameraObjectRender(HDC hdc);
	string cameraOCollision(RECT rc, string me);
	void cameraObjectClear() { _vO.clear(); }

};
