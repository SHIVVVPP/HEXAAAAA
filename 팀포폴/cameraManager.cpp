#include "stdafx.h"
#include "cameraManager.h"


cameraManager::cameraManager()
{
}


cameraManager::~cameraManager()
{

}


//카메라 초기 설정
HRESULT cameraManager::init(void)
{
	//초기 카메라 위치 배경 크기의 중앙으로 설정
	_camera.x = (BACKGROUND_LIMIT_X - BACKGROUND_START_X) / 2 - WINSIZEX / 2;
	_camera.y = (BACKGROUND_LIMIT_Y - BACKGROUND_START_Y) / 2 - WINSIZEY / 2;
	BACKGROUND_START_X = 0;
	BACKGROUND_START_Y = 0;
	_cameraConditionX = CAMERA_FREE;
	_aim = NULL;
	return S_OK;
}
void cameraManager::release(void)
{

}

//카메라 UPDATE() gameNode의 update()에서 실행된다.
void cameraManager::update(void)
{
	switch (_cameraConditionX)
	{
	case CAMERA_MOVING:

		int k;
		if (_destX > _camera.x)
		{
			_camera.x += _speedX;
			if (_destX < _camera.x)
				_camera.x = _destX;
		}
		else
		{
			_camera.x -= _speedX;
			if (_destX > _camera.x)
				_camera.x = _destX;
		}
		cameraRevision();

		if (_currentO_X != NULL)
		{
			_currentO_X->prevCameraLimit.x > _currentO_X->nextCameraLimit.x ? BACKGROUND_START_X = _currentO_X->nextCameraLimit.x : BACKGROUND_START_X = _currentO_X->prevCameraLimit.x;
			_currentO_X->prevCameraLimit.y > _currentO_X->nextCameraLimit.y ? BACKGROUND_LIMIT_X = _currentO_X->prevCameraLimit.y : BACKGROUND_LIMIT_X = _currentO_X->nextCameraLimit.y;


			if (_currentO_X->toNext)
			{

				if (_currentO_X->nextCondition == CAMERA_AIMING && 
						(
							(_currentO_X->nextCameraLimit.y - getCenterX(*_currentO_X->_aim) <WINSIZEX/2 && _camera.x == _currentO_X->nextCameraLimit.y - WINSIZEX)||
							(getCenterX(*_currentO_X->_aim) - _currentO_X->nextCameraLimit.x < WINSIZEX/2 && _camera.x == _currentO_X->nextCameraLimit.x)||
							(_currentO_X->nextCameraLimit.y - getCenterX(*_currentO_X->_aim) > WINSIZEX / 2 && getCenterX(*_currentO_X->_aim) - _currentO_X->nextCameraLimit.x > WINSIZEX / 2
								&& ((_speedX >0 && _camera.x + WINSIZEX/2 < getCenterX(*_currentO_X->_aim))||(_speedX<0 && _camera.x+WINSIZEX/2 >getCenterX(*_currentO_X->_aim)))
								)
						)
					)
				{
					BACKGROUND_START_X = _currentO_X->nextCameraLimit.x;
					BACKGROUND_LIMIT_X = _currentO_X->nextCameraLimit.y;
					_cameraConditionX = CAMERA_AIMING;
					setCameraAim(_currentO_X->_aim);
					_currentO_X->moveFinish = true;
				}
			}
			else
			{
				if (_currentO_X->prevCondition == CAMERA_AIMING &&
					(
					(_currentO_X->prevCameraLimit.y - getCenterX(*_currentO_X->_aim) <WINSIZEX / 2 && _camera.x == _currentO_X->prevCameraLimit.y - WINSIZEX) ||
						(getCenterX(*_currentO_X->_aim) - _currentO_X->prevCameraLimit.x < WINSIZEX / 2 && _camera.x == _currentO_X->prevCameraLimit.x) ||
						(_currentO_X->prevCameraLimit.y - getCenterX(*_currentO_X->_aim) > WINSIZEX / 2 && getCenterX(*_currentO_X->_aim) - _currentO_X->prevCameraLimit.x > WINSIZEX / 2
							&& ((_speedX >0 && _camera.x + WINSIZEX / 2 < getCenterX(*_currentO_X->_aim)) || (_speedX<0 && _camera.x + WINSIZEX / 2 >getCenterX(*_currentO_X->_aim)))
							)
						)
					)
				{
					BACKGROUND_START_X = _currentO_X->prevCameraLimit.x;
					BACKGROUND_LIMIT_X = _currentO_X->prevCameraLimit.y;

					_cameraConditionX = CAMERA_AIMING;
					setCameraAim(_currentO_X->_aim);
					_currentO_X->moveFinish = true;

				}
			
			}
		}
		

		break;
	case CAMERA_AIMING:
		cameraFollow(false);
		break;
	case CAMERA_EFFECT:
		cameraEffecting(false);
		break;
	}

	switch (_cameraConditionY)
	{
	case CAMERA_MOVING:


		
		if (_destY > _camera.y)
		{
			_camera.y += _speedY;
			if (_destY < _camera.y)
				_camera.y = _destY;
		}
		else
		{
			_camera.y -= _speedY;
			if (_destY > _camera.y)
				_camera.y = _destY;
		}
		cameraRevision();

		if (_currentO_Y != NULL)
		{
			_currentO_Y->prevCameraLimit.x > _currentO_Y->nextCameraLimit.x ? BACKGROUND_START_Y = _currentO_Y->nextCameraLimit.x : BACKGROUND_START_Y = _currentO_Y->prevCameraLimit.x;
			_currentO_Y->prevCameraLimit.y > _currentO_Y->nextCameraLimit.y ? BACKGROUND_LIMIT_Y = _currentO_Y->prevCameraLimit.y : BACKGROUND_LIMIT_Y = _currentO_Y->nextCameraLimit.y;

			if (_currentO_Y->toNext)
			{
				if (_currentO_Y->nextCondition == CAMERA_AIMING &&
					(
					(_currentO_Y->nextCameraLimit.y - getCenterY(*_currentO_Y->_aim) <WINSIZEY / 2 && _camera.y == _currentO_Y->nextCameraLimit.y - WINSIZEY) ||
						(getCenterY(*_currentO_Y->_aim) - _currentO_Y->nextCameraLimit.x < WINSIZEY / 2 && _camera.y == _currentO_Y->nextCameraLimit.x) ||
						(_currentO_Y->nextCameraLimit.y - getCenterY(*_currentO_Y->_aim) > WINSIZEY / 2 && getCenterY(*_currentO_Y->_aim) - _currentO_Y->nextCameraLimit.x > WINSIZEY / 2
							&& ((_speedY >0 && _camera.y + WINSIZEY / 2 < getCenterY(*_currentO_Y->_aim)) || (_speedY<0 && _camera.y + WINSIZEY / 2 >getCenterY(*_currentO_Y->_aim)))
							)
						)
					)
				{
					BACKGROUND_START_Y = _currentO_Y->nextCameraLimit.x;
					BACKGROUND_LIMIT_Y = _currentO_Y->nextCameraLimit.y;
					_cameraConditionY = CAMERA_AIMING;
					setCameraAim(_currentO_Y->_aim);
					_currentO_X->moveFinish = true;

				}
			}
			else
			{
					if (_currentO_Y->prevCondition == CAMERA_AIMING &&
						(
						(_currentO_Y->prevCameraLimit.y - getCenterY(*_currentO_Y->_aim) <WINSIZEY / 2 && _camera.y == _currentO_Y->prevCameraLimit.y - WINSIZEY) ||
							(getCenterY(*_currentO_Y->_aim) - _currentO_Y->prevCameraLimit.x < WINSIZEY / 2 && _camera.y == _currentO_Y->prevCameraLimit.x) ||
							(_currentO_Y->prevCameraLimit.y - getCenterY(*_currentO_Y->_aim) > WINSIZEY / 2 && getCenterY(*_currentO_Y->_aim) - _currentO_Y->prevCameraLimit.x > WINSIZEY / 2
								&& ((_speedY >0 && _camera.y + WINSIZEY / 2 < getCenterY(*_currentO_Y->_aim)) || (_speedY<0 && _camera.y + WINSIZEY / 2 >getCenterY(*_currentO_Y->_aim)))
								)
							)
						)
					{
						BACKGROUND_START_Y = _currentO_Y->prevCameraLimit.x;
						BACKGROUND_LIMIT_Y = _currentO_Y->prevCameraLimit.y;

						_cameraConditionY = CAMERA_AIMING;
						_aim = _currentO_Y->_aim;
						_currentO_X->moveFinish = true;

					}
				
			}
		}

		break;
	case CAMERA_AIMING:
		cameraFollow(true);
		break;
	case CAMERA_EFFECT:
		cameraEffecting(true);
		break;
	}


}

//매개변수로 받는 RECT를 중심으로 카메라를 이동시키는 함수
void cameraManager::setCameraAim(RECT * rc)
{
	int centerX, centerY;
	if (_cameraConditionX == CAMERA_AIMING)
	{
		_aim = rc;
		centerX = (rc->left + rc->right) / 2;
		_camera.x = centerX - WINSIZEX / 2;
	}

	if (_cameraConditionY == CAMERA_AIMING)
	{
		_aim = rc;
		centerY = (rc->top + rc->bottom) / 2;
		_camera.y = centerY - WINSIZEY / 2;
	}

	cameraRevision();
}


//매개변수로 받은 RC가 현재 카메라범위 안쪽에 있는지 판단하여 TRUE나 FALSE를 반환하는 함수
bool cameraManager::isInCamera(RECT rc)
{
	RECT temp;
	if (IntersectRect(&temp,&rc,&(RectMake(_camera.x,_camera.y,WINSIZEX,WINSIZEY)))) return true;
	else return false;
}

//카메라가   화면 밖으로 나갈 시 보정해주는 함수
void cameraManager::cameraRevision()
{
	if (_camera.x < BACKGROUND_START_X)
	{
		_camera.x = BACKGROUND_START_X;
	}
	else if (_camera.x > BACKGROUND_LIMIT_X - WINSIZEX)
	{
		_camera.x = BACKGROUND_LIMIT_X - WINSIZEX;
	}

	if (_camera.y < BACKGROUND_START_Y)
	{
		_camera.y = BACKGROUND_START_Y;
	}
	else if (_camera.y > BACKGROUND_LIMIT_Y - WINSIZEY)
	{
		_camera.y = BACKGROUND_LIMIT_Y - WINSIZEY;
	}
}

//이펙트를 주고싶을때 쓰는함수 EFFECT 종류, 세기, 시간(초)
void cameraManager::setEffect(int effectIndex, float strong, float time)
{
	if (_cameraConditionX != CAMERA_EFFECT)
		_prevCameraConditionX = _cameraConditionX;
	_cameraConditionX = CAMERA_EFFECT;
	_effectIndex = effectIndex;
	_maxEffectT_X = time * 60;
	_strongX = strong;
	_effectT_X = 0;
	originX = _camera.x;
	originY = _camera.y;
}

//이펙트 함수 _cameraCondition 이 CAMERA_EFFECT일때 실행된다.
void cameraManager::cameraEffecting(bool vertical)
{

	if (vertical)
	{
		switch (_effectIndex)
		{
		case EFFECT_SIN:
			_camera.y = originY + _strongY * sinf(_effectT_Y);
			break;
		}
		//cameraRevision();
		_effectT_X++;

		cameraRevision();

		if (_effectT_Y > _maxEffectT_Y)
		{
			_cameraConditionY = _prevCameraConditionY;
		}
	}
	else
	{
		switch (_effectIndex)
		{
		case EFFECT_SIN:
			_camera.x = originX + _strongX * sinf(_effectT_X);
			break;
		}
		_effectT_X++;

		cameraRevision();

		if (_effectT_X > _maxEffectT_X)
		{
			_cameraConditionX = _prevCameraConditionX;
		}
	}
}


void cameraManager::cameraMoveTo(bool vertical, int dest, float speed)
{
	if (vertical)
	{
		_destY = dest;
		_speedY = speed;
		_cameraConditionY = CAMERA_MOVING;
	}
	else
	{
		_destX = dest;
		_speedX = speed;
		_cameraConditionX = CAMERA_MOVING;
	}
}

void cameraManager::cameraFollow(bool vertical)
{
	int centerX, centerY;
	if (vertical)
	{
		centerY = (_aim->top + _aim->bottom) / 2;
		_camera.y = centerY - WINSIZEY / 2;
	}
	else
	{
		centerX = (_aim->left + _aim->right) / 2;
		_camera.x = centerX - WINSIZEX / 2;
	}
	cameraRevision();
}


void cameraManager::addCameraObject(bool vertical, bool sence_vertical,int type, int nextCameraCondition, RECT rc, POINT prevLimit, POINT nextLimit, RECT * aim,bool left_top, string num)
{
	CAMERA_OBJECT temp;
	temp._type = type;
	temp.isVertical = vertical;
	temp.sence_vertical = sence_vertical;
	temp.left_top = left_top;
	temp.nextCondition = nextCameraCondition;
	temp.num = num;

	temp.nextCameraLimit = nextLimit;
	temp.prevCameraLimit =	prevLimit;
	temp._aim = aim;
	temp._rc = rc;
	_vO.push_back(temp);
}

void cameraManager::cameraObjectRender(HDC hdc)
{
	for (int i = 0; i < _vO.size(); i++)
	{
		HBRUSH hBrush, hOldBrush;
		HPEN hPen, hOldPen;
		hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		//CAMERARECTANGLE
		hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		hOldPen = (HPEN)SelectObject(hdc, hPen);
		RectangleMake(hdc, CameraRelativePointX(_vO[i]._rc.left), CameraRelativePointY(_vO[i]._rc.top), _vO[i]._rc.right - _vO[i]._rc.left, _vO[i]._rc.bottom - _vO[i]._rc.top);
		if (_vO[i].isVertical) LineMake(hdc, CameraRelativePointX((_vO[i]._rc.left + _vO[i]._rc.right) / 2),
			CameraRelativePointY(_vO[i]._rc.bottom),
			CameraRelativePointX((_vO[i]._rc.left + _vO[i]._rc.right) / 2),
			CameraRelativePointY(_vO[i]._rc.top));
		else LineMake(hdc, 
			CameraRelativePointX(_vO[i]._rc.left),
			CameraRelativePointY((_vO[i]._rc.top + _vO[i]._rc.bottom) / 2),
			CameraRelativePointX(_vO[i]._rc.right), 
			CameraRelativePointY((_vO[i]._rc.top + _vO[i]._rc.bottom) / 2));
		SelectObject(hdc, hOldPen);
		SelectObject(hdc, hOldBrush);
		DeleteObject(hPen);
		DeleteObject(hBrush);

		char str[128];
		sprintf(str, "progress x %0.2f progress y %0.2f \n CAMERASTART X %d Y %d \n CAMERALIMIT X %d Y %d", _vO[i].progressX, _vO[i].progressY, BACKGROUND_START_X, BACKGROUND_START_Y,
			BACKGROUND_LIMIT_X, BACKGROUND_LIMIT_Y);
		TextOut(hdc, 0, WINSIZEY - 20, str, strlen(str));
		if (_vO[i].toNext)
		{
			if (_vO[i].isVertical)
				sprintf(str, "ToNext VERTICAL prev TB %d,%d  next TB %d,%d", _vO[i].prevCameraLimit.x, _vO[i].prevCameraLimit.y, _vO[i].nextCameraLimit.x, _vO[i].nextCameraLimit.y);
			else
				sprintf(str, "ToNext HORIZONTAL prev LR %d,%d  next LR %d,%d", _vO[i].prevCameraLimit.x, _vO[i].prevCameraLimit.y, _vO[i].nextCameraLimit.x, _vO[i].nextCameraLimit.y);

		}
		else
		{
			if(_vO[i].isVertical)
			sprintf(str, "ToPrev VERTICAL prev TB %d,%d  next TB %d,%d", _vO[i].prevCameraLimit.x, _vO[i].prevCameraLimit.y, _vO[i].nextCameraLimit.x, _vO[i].nextCameraLimit.y);
			else
			sprintf(str, "ToPrev HORIZONTAL prev LR %d,%d  next LR %d,%d", _vO[i].prevCameraLimit.x, _vO[i].prevCameraLimit.y, _vO[i].nextCameraLimit.x, _vO[i].nextCameraLimit.y);
		}
		TextOut(hdc, 0, WINSIZEY - 50 - 20*i, str, strlen(str));
	}
	char str[128];

	sprintf(str, "camera X %d Y %d", _camera.x, _camera.y);
	TextOut(hdc, 0,200, str, strlen(str));
}

string cameraManager::cameraOCollision(RECT rc,string me)
{
	RECT temp;
	RECT col;
	CAMERA_OBJECT* _co;
	for (int i = 0; i < _vO.size(); i++)
	{
		if (!IntersectRect(&temp, &rc, &_vO[i]._rc)) continue;
		_co = &_vO[i];
		
		//감지 -> toNext결정
		if (_vO[i].sence_vertical)
		{
			bool tNext = _co->toNext;
			if (!PtInRect(&temp, { (rc.left + rc.right) / 2 ,_co->prevP }))_co->prevP = (temp.bottom + temp.top) / 2;
			if (_co->left_top)
			{
				if (_co->prevP < (temp.top + temp.bottom) / 2) {
					_co->toNext = true;
				}
				else if (_co->prevP > (temp.top + temp.bottom) / 2) {
					_co->toNext = false;
				}
			}
			else
			{
				if (_co->prevP < (temp.top + temp.bottom) / 2) {
					_co->toNext = false;
				}
				else if (_co->prevP > (temp.top + temp.bottom) / 2) {
					_co->toNext = true;
				}
			}
			if (tNext != _co->toNext) _co->moveFinish = false;
		}
		else
		{
			bool tNext = _co->toNext;

			if (!PtInRect(&temp, { _co->prevP,(rc.top + rc.bottom) / 2  }))_co->prevP = (temp.left + temp.right) / 2;

			if (_co->left_top)
			{
				if (_co->prevP < (temp.left + temp.right) / 2) {
					_co->toNext = true;
				}
				else if (_co->prevP > (temp.left + temp.right) / 2) {
					_co->toNext = false;
				}
			}
			else
			{
				if (_co->prevP < (temp.left + temp.top) / 2) {
					_co->toNext = false;
				}
				else if (_co->prevP > (temp.left + temp.top) / 2)
				{
					_co->toNext = true;
				}
			}
			if (tNext != _co->toNext) _co->moveFinish = false;

		}
		/*RECT _rc;
		int _type;
		int prevCondition, nextCondition;
		float progressX;
		float progressY;
		bool isVertical;
		bool left_top;
		POINT nextCameraLimit;
		POINT prevCameraLimit;
		RECT* _aim;
		bool collisionCheck;
		bool toNext;
		int prevP;*/

		// horizontal 이동, vertical이동
		if (_vO[i].isVertical && !_co->moveFinish)
		{
			_currentO_Y = _co;
			if (!PtInRect(&temp, { _co->prevP,(rc.top + rc.bottom) / 2 })) _co->prevP = (temp.left + temp.right) / 2;

			if (_cameraConditionY != CAMERA_MOVING) _co->prevCondition = _cameraConditionY;

			switch (_vO[i]._type)
			{
			case C_OBJECT_MOVE:
				if (_co->toNext)
				{
					cameraMoveTo(true, _co->nextCameraLimit.x, 3);
				}
				else
				{
					cameraMoveTo(true, _co->prevCameraLimit.x, 3);
				}
				_cameraConditionY = CAMERA_MOVING;

				break;
			case C_OBJECT_MOVE2:

				break;
			}

			if (_vO[i].sence_vertical)
			{
				_vO[i].prevP = (temp.top + temp.bottom) / 2;
			}
			else
			{
				_vO[i].prevP = (temp.left + temp.right) / 2;
			}

		}
		else if(!_co->moveFinish){
			_currentO_X = _co;
			if (_cameraConditionX != CAMERA_MOVING) _co->prevCondition = _cameraConditionX;

			

			switch (_vO[i]._type)
			{
			case C_OBJECT_MOVE:
				if (_co->toNext)
				{
					cameraMoveTo(false, _co->nextCameraLimit.x, 3);
				}
				else
				{
					cameraMoveTo(false, _co->prevCameraLimit.x, 3);
				}
				_cameraConditionX = CAMERA_MOVING;
				break;
			case C_OBJECT_MOVE2:

				break;
			}
			if (_vO[i].sence_vertical)
			{
				_vO[i].prevP = (temp.top + temp.bottom) / 2;
			}
			else
			{
				_vO[i].prevP = (temp.left + temp.right) / 2;
			}
		}

		if (_co->toNext) {
			string temp = _co->num;
			_co->num = me;
			return temp;
		}
		else return _co->num;
	}

	return "empty";

}
