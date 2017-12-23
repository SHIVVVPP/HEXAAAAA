#pragma once
#include "singletonBase.h"
#include <vector>

//stdafx.h에  BACKGROUNDSIZEX,Y DEFINE추가 CAMERAMANAGER DEFINE 추가 GAMENODE에 CAMERAMANAGER INIT() UPDATE()

#define CAMERA_VERTICAL 0
#define CAMERA_HORIZONTAL 1

//카메라 상태값 수직 수평
#define CAMERA_FREE 0 //카메라가 자유롭게 이동할 수 있음
#define CAMERA_AIMING 1 //카메라가 aim 으로 설정된 rc를 따라감
#define CAMERA_EFFECT 2 //카메라 흔들림, 효과 처리
#define CAMERA_MOVING 3 //카메라 이동처리

//카메라 오브젝트 타입
#define C_OBJECT_MOVE 0
#define C_OBJECT_MOVE2 1


//이펙트
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
	// 해당하는 rc로 카메라를 설정합니다.
	void setCameraAim(RECT* rc);

	// object가 카메라 화면 안쪽에 있는지 알아냅니다.
	bool isInCamera(RECT rc);

	void cameraMoveTo(bool vertical, int dest,float speed);

	void cameraFollow(bool vertical);


	// CAMERA_FREE, CAMERA_AIMING, CAMERA_EFFEICTING, CAMERA_MOVING로 카메라 상태를 설정합니다.
	inline	void setCameraCondition(bool vertical,int cameraCondition) {if(vertical) _cameraConditionY = cameraCondition; else _cameraConditionX = cameraCondition;
	}

	//카메라에 화면상 좌표를 반환합니다.
	inline POINT CameraRelativePoint(RECT rc) { return { rc.left - _camera.x, rc.top - _camera.y }; }
	inline int CameraRelativePointX(int x) { return  x - _camera.x; }
	inline int CameraRelativePointY(int y) { return y - _camera.y; }

	//카메라가 위치를 벗어나면 보정한다.
	inline void cameraRevision();

	// 카메라 이펙트 설정 EFFECT_SIN,..., 강도, 시간(초)
	inline void setEffect(int effectIndex, float strong, float time);

	//카메라 이펙팅
	inline void cameraEffecting(bool vertical);

	inline int getCameraCondition() { return _cameraConditionX; }

	inline POINT getCameraPoint() { return _camera; }

	//카메라 오브젝트



	/*RECT _rc;
	int prevCondition, inCondition, nextCondition;
	float progress;
	tagRect nextCameraLimit;
	tagRect prevCameraLimit;
	RECT* _aim;*/
	void  addCameraObject(bool vertical,bool senceside,int objectType, int nextCameraCondition, RECT rc, POINT prevLimit, POINT nextLimit, RECT* aim, bool left_top);
	void cameraObjectRender(HDC hdc);
	void cameraOCollision(RECT rc);
	void cameraObjectClear() { _vO.clear(); }

};
