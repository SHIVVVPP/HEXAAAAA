#include "stdafx.h"
#include "skeleton.h"


skeleton::skeleton()
{

}


skeleton::~skeleton()
{
}

HRESULT skeleton::init(MONSTER_INDEX mon_index, POINT leftX_topY)
{
	_index = mon_index;
	_leftX = leftX_topY.x;
	_topY = leftX_topY.y;
	_image = IMAGEMANAGER->findImage("ÇØ°ñ");
	_width = 100;//28  37
	_height = 144;

	_hp = 3;

	_isRight = false;
	_detect = false;
	_speedX = 2;
	_sumGravity = 0;

	_ani = new animation;

	int rightStay[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_RIGHT_STAY", "ÇØ°ñ", rightStay, 1, 1, true);
	int leftStay[] = { 20 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_LEFT_STAY", "ÇØ°ñ", leftStay, 1, 1, true);
	int rightMove[] = { 4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_RIGHT_MOVE", "ÇØ°ñ", rightMove, 4, 1, true);
	int leftMove[] = { 24,25,26,27 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_LEFT_MOVE", "ÇØ°ñ", leftMove, 4, 1, true);
	int rightBackMove[] = { 8,9 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_RIGHT_BACKMOVE", "ÇØ°ñ", rightBackMove, 2, 1, true);
	int leftBackMove[] = { 28,29 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_LEFT_BACKMOVE", "ÇØ°ñ", leftBackMove, 2, 1, true);
	int rightAttack[] = { 12,13 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_RIGHT_ATTACK", "ÇØ°ñ", rightAttack, 2, 1, false);
	int leftAttack[] = { 30,31 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_LEFT_ATTACK", "ÇØ°ñ", leftAttack, 2, 1, false);
	int rightDie[] = { 16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_RIGHT_DIE", "ÇØ°ñ", rightDie, 4, 1, false);
	int leftDie[] = { 36,37,38,39 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_LEFT_DIE", "ÇØ°ñ", leftDie, 4, 1, false);


	_mainCondition = STAND;
	_subCondition = LAND;
	setCondition();

	return S_OK;

}
void skeleton::release()											 
{
}
void skeleton::update()
{
	float d = getDistance(_collisionRc.left + _width / 2, _collisionRc.top + _height / 2, (_playerC->left + _playerC->right) / 2, (_playerC->top + _playerC->bottom) / 2);
	float angle = getAngle(_collisionRc.left + _width / 2, _collisionRc.top + _height / 2, (_playerC->left + _playerC->right) / 2, (_playerC->top + _playerC->bottom) / 2);

	if (d < 400) _detect = true;
	else _detect = false;

	if (_detect)
	{
		if (cosf(angle) > 0)
		{
			if (d < 100)
			{
				if(!_isRight) changeDirection();
				setMainCondition(BACKMOVE);
			}
			else
			{
				if (_isRight) changeDirection();
				setMainCondition(MOVE);
			}
		}
		else if (cosf(angle) < 0)
		{
			if (d < 100)
			{
				if (_isRight) changeDirection();
				setMainCondition(BACKMOVE);
			}
			else
			{
				if (!_isRight) changeDirection();
				setMainCondition(MOVE);
			}
		}
	}


	if (_mainCondition == MOVE)
	{
		if (_isRight)
			_leftX += _speedX;
		else
			_leftX -= _speedX;
	}

	if (_mainCondition == BACKMOVE)
	{
		if (_isRight)
			_leftX -= _speedX;
		else
			_leftX += _speedX;
	}

	if (_subCondition == FALL)
	{
		_sumGravity += 0.1f;
		_topY += _sumGravity;
	}


	_imageRc = RectMake(_leftX+_width/2- _image->getFrameWidth()/2, _topY-40, _image->getFrameWidth(), _image->getFrameHeight());
	_collisionRc = RectMake(_leftX, _topY, _width, _height);

	_ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 1);
}
void skeleton::render()												 
{
	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_collisionRc.left), CAMERAMANAGER->CameraRelativePointY(_collisionRc.top), _width, _height);
	_image->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_imageRc.left), CAMERAMANAGER->CameraRelativePointY(_imageRc.top), _ani);
}

void skeleton::CollisionReact()
{
}

void skeleton::setMainCondition(MONSTER_MAINCONDITION mainCondition)
{
	if (_mainCondition != mainCondition)
	{
		_mainCondition = mainCondition;
		setCondition();
	}
}
void skeleton::setSubCondition(MONSTER_SUBCONDITION subCondition)	
{
	if (_subCondition != subCondition)
	{
		_subCondition = subCondition;
		setCondition();
	}
}
void skeleton::setCondition()										
{
	switch (_mainCondition)
	{
	case STAND:
		switch (_subCondition)
		{
		case LAND:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_STAY");
			else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_STAY");
			_sumGravity = 0;
		break;
		case ATTACK:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_ATTACK");
			else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_ATTACK");
			_sumGravity = 0;
		break;
		case FALL:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_STAY");
			else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_STAY");
		break;
		}
	break;
	case MOVE:
		switch (_subCondition)
		{
		case LAND:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_MOVE");
			else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_MOVE");
			_sumGravity = 0;
		break;
		case ATTACK:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_ATTACK");
			else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_ATTACK");
			_sumGravity = 0;
		break;
		case FALL:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_MOVE");
			 else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_MOVE");
		break;
		}
	break;
	case BACKMOVE:
		switch (_subCondition)
		{
		case LAND:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_BACKMOVE");
			else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_BACKMOVE");
			_sumGravity = 0;
		break;
		}
	break;
	case DIE:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_DIE");
			else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_DIE");
			_sumGravity = 0;
	break;
	}


	_imageRc = RectMake(_leftX + _width / 2 - _image->getFrameWidth() / 2, _topY - 40, _image->getFrameWidth(), _image->getFrameHeight());
	_collisionRc = RectMake(_leftX, _topY, _width, _height);
		
	 	_ani->start();
}

void skeleton::changeDirection()
{
	if (_isRight) _leftX -= 100;
	enemy::changeDirection();
}