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
	_image = IMAGEMANAGER->findImage("레드비틀");
	_width = _image->getFrameWidth();
	_height = _image->getFrameHeight();

	_hp = 1;

	_isRight = false;


	_speedX = 1;
	_sumGravity = 0;
	
	_ani = new animation;
	
	int rightMove[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("REDBEETLE_RIGHT_MOVE", "레드비틀", rightMove, 4, 1, true);
	int leftMove[] = { 8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("REDBEETLE_LEFT_MOVE", "레드비틀", leftMove, 4, 1, true);
	int rightDie[] = { 4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("REDBEETLE_RIGHT_DIE", "레드비틀", rightDie, 2, 1, false);
	int leftDie[] = { 14,15 };
	KEYANIMANAGER->addArrayFrameAnimation("REDBEETLE_LEFT_DIE", "레드비틀", leftDie, 2, 1, false);
	_attackCount = 0;
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
		_sumGravity += 0.1f;
		_topY += _sumGravity;
	}

	if (_mainCondition == DIE)
	{
		if (_attackCount > 100)
			_mainCondition = DYINGOUT;
		_attackCount++;
	}

	

	_imageRc = RectMake(_leftX, _topY, _width, _height);
	_collisionRc = RectMake(_leftX, _topY, _width, _height);
	
	_ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 1);
}
void redBeetle::render()												   
{
	_image->aniRender(getMemDC(),CAMERAMANAGER->CameraRelativePointX( _leftX),CAMERAMANAGER->CameraRelativePointY( _topY), _ani);
	//RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY), _width, _height);
}

void redBeetle::CollisionReact()
{
	_hp--;
	if (_hp <= 0)
		setMainCondition(DIE);
}

void redBeetle::setMainCondition(MONSTER_MAINCONDITION mainCondition)		
{
	if (_mainCondition != mainCondition)
	{
		_mainCondition = mainCondition;
		setCondition();
	}
}
void redBeetle::setSubCondition(MONSTER_SUBCONDITION subCondition)			
{
	if (_subCondition != subCondition)
	{
		_subCondition = subCondition;
		setCondition();
	}
}

void redBeetle::setCondition()
{
	_ani->stop();
	switch (_mainCondition)
	{
	case MOVE:
		switch (_subCondition)
		{
		case LAND:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_RIGHT_MOVE");
			else
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_LEFT_MOVE");
			_sumGravity = 0;
		break;
		case FALL:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_RIGHT_MOVE");
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
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_RIGHT_DIE");
			else
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_LEFT_DIE");
			_sumGravity = 0;
		break;
		case FALL:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_RIGHT_DIE");
			else
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_LEFT_DIE");
		break;
		}
		break;
	case DYINGOUT:
		switch (_subCondition)
		{
		case LAND:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_RIGHT_DIE");
			else
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_LEFT_DIE");
			_sumGravity = 0;
			break;
		case FALL:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("REDBEETLE_RIGHT_DIE");
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