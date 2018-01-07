#include "stdafx.h"
#include "redBeetle.h"


redBeetle::redBeetle()
{
	
}


redBeetle::~redBeetle()
{
}

HRESULT redBeetle::init(MONSTER_INDEX mon_index, POINT leftX_topY)		   
{
	_index = mon_index;
	_leftX = leftX_topY.x;
	_topY = leftX_topY.y;
	_image = IMAGEMANAGER->findImage("�����Ʋ");
	_width = _image->getFrameWidth();
	_height = _image->getFrameHeight();
	_cx = _leftX + _width / 2;
	_cy = _topY + _height / 2;

	_hp = 1;

	_isRight = false;

	_range.x = _cx - 100;
	_range.y = _cx + 100;

	_speedX = 1;
	_sumGravity = 0;
	
	_ani = new animation;
	
	int rightMove[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("REDBEETLE_Right_MOVE", "�����Ʋ", rightMove, 4, 1, true);
	int leftMove[] = { 8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("REDBEETLE_LEFT_MOVE", "�����Ʋ", leftMove, 4, 1, true);
	int rightDie[] = { 4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("REDBEETLE_RIGHT_DIE", "�����Ʋ", rightDie, 2, 1, false);
	int leftDie[] = { 14,15 };
	KEYANIMANAGER->addArrayFrameAnimation("REDBEETLE_LEFT_DIE", "�����Ʋ", leftDie, 2, 1, false);
	
	_mainCondition = MOVE;
	_subCondition = LAND;
	setCondition();

	return S_OK;
}
void redBeetle::release()												   
{
}
void redBeetle::update()												   
{
	if (_mainCondition == MOVE)
	{
		if (_isRight)
			_leftX += _speedX;
		else
			_leftX -= _speedX;
	}
	
	if (_subCondition == FALL)
	{
		_sumGravity += 0.01f;
		_topY += _sumGravity;
	}


	if ((_isRight && _leftX + _width > _range.y) || (!_isRight && _leftX < _range.x))
		changeDirection();

	_imageRc = RectMake(_leftX, _topY, _width, _height);
	_collisionRc = RectMakeCenter(_leftX+_width/2, _topY+_height/2, _width, _height);
	
	_ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 1);
}
void redBeetle::render()												   
{
	_image->aniRender(getMemDC(),CAMERAMANAGER->CameraRelativePointX( _leftX),CAMERAMANAGER->CameraRelativePointY( _topY), _ani);
	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY), _width, _height);
}

void redBeetle::CollisionReact()
{
}

void redBeetle::setMainCondition(MONSTER_MAINCONDITION mainCondition)		
{
	_mainCondition = mainCondition;
	setCondition();
}
void redBeetle::setSubCondition(MONSTER_SUBCONDITION subCondition)			
{
	_subCondition = subCondition;
	setCondition();
}

void redBeetle::setCondition()
{
	switch (_mainCondition)
	{
	case MOVE:
		switch (_subCondition)
		{
		case LAND:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_Right_MOVE");
			else
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_LEFT_MOVE");
			_sumGravity = 0;
		break;
		case FALL:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_Right_MOVE");
			else
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_LEFT_MOVE");
		break;
		}
		break;
	case DIE:
		switch (_subCondition)
		{
		case LAND:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_Right_DIE");
			else
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_LEFT_DIE");
			_sumGravity = 0;
		break;
		case FALL:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_Right_DIE");
			else
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_LEFT_DIE");
		break;
		}
		break;
	}


	_imageRc = RectMake(_leftX, _topY, _width, _height);
	_collisionRc = RectMake(_leftX, _topY, _width, _height);
	_ani->start();
}