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
	_attackCount = 0;
	_hp = 3;

	_alpha = 255;
	_isRight = false;
	_detect = false;
	_speedX = 1;
	_sumGravity = 0;
	_sumNuckBack = 10;

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
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_RIGHT_ATTACK", "ÇØ°ñ", rightAttack, 2, 1, false,attackReturn,this);
	int leftAttack[] = { 33,32 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_LEFT_ATTACK", "ÇØ°ñ", leftAttack, 2, 1, false, attackReturn, this);
	int rightDie[] = { 16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_RIGHT_DIE", "ÇØ°ñ", rightDie, 4, 1, false, dieReturn,this);
	int leftDie[] = { 36,37,38,39 };
	KEYANIMANAGER->addArrayFrameAnimation("SKELETON_LEFT_DIE", "ÇØ°ñ", leftDie, 4, 1, false, dieReturn,this);


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
	float d = getDistance( (_playerC->left + _playerC->right) / 2, (_playerC->top + _playerC->bottom) / 2, _collisionRc.left + _width / 2, _collisionRc.top + _height / 2);
	float angle = getAngle((_playerC->left + _playerC->right) / 2, (_playerC->top + _playerC->bottom) / 2, _collisionRc.left + _width / 2, _collisionRc.top + _height / 2);

	if (d < 400) _detect = true;
	else _detect = false;

	if (_detect)
	{
		if (d < 150 )
		{
			if (_attackCount % 30 == 0)
			{
				setMainCondition(STAND);
				setSubCondition(ATTACK);
				_attackCount = 0;
			}
			_attackCount++;
		}

		
		if (cosf(angle) > 0)
		{
				if (_isRight) changeDirection();
				setMainCondition(MOVE);
		}
		else if (cosf(angle) < 0)
		{
				if (!_isRight) changeDirection();
				setMainCondition(MOVE);
		}
	}


	if (_mainCondition == MOVE)
	{
		if (_isRight)
			_leftX += _speedX;
		else
			_leftX -= _speedX;
	}
	if (_mainCondition == HITTED)
	{
		_sumNuckBack -= 0.5f;
		if (_isRight) _leftX -= _sumNuckBack;
		else _leftX += _sumNuckBack;

		if (_sumNuckBack <= 0) {
			_mainCondition = STAND;
			setCondition();
		}

		_alpha -= 30;
		if (_alpha <= 0) _alpha = 255;
	}

	if (_subCondition == FALL)
	{
		_sumGravity += 0.1f;
		_topY += _sumGravity;
	}



	if (_subCondition == ATTACK)
	{
		if (_isRight)
		{
			_imageRc = RectMake(_leftX + _width / 2 - _image->getFrameWidth() / 2, _topY - 40, _image->getFrameWidth(), _image->getFrameHeight());
			_collisionRc = RectMake(_leftX, _topY, _imageRc.right - _leftX, _height);
		}
		else
		{
			_imageRc = RectMake(_leftX + _width / 2 - _image->getFrameWidth() / 2, _topY - 40, _image->getFrameWidth(), _image->getFrameHeight());
			_collisionRc = RectMake(_leftX + _width / 2 - _image->getFrameWidth() / 2, _topY, _imageRc.right - _leftX, _height);

		}
	}
	else
	{
		_imageRc = RectMake(_leftX + _width / 2 - _image->getFrameWidth() / 2, _topY - 40, _image->getFrameWidth(), _image->getFrameHeight());
		_collisionRc = RectMake(_leftX, _topY, _width, _height);
	}


	_ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 1);
}
void skeleton::render()												 
{
	if (_mainCondition == HITTED)
	{
		_image->aniAlphaRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_imageRc.left), CAMERAMANAGER->CameraRelativePointY(_imageRc.top),_alpha, _ani);

	}
	else
	_image->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_imageRc.left), CAMERAMANAGER->CameraRelativePointY(_imageRc.top), _ani);

	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_collisionRc.left), CAMERAMANAGER->CameraRelativePointY(_collisionRc.top), _collisionRc.right - _collisionRc.left, _collisionRc.bottom - _collisionRc.top);

}

void skeleton::CollisionReact()
{
	_hp--;
	if (_hp <= 0)
	{
		_mainCondition = DIE;
		setCondition();
	}
	else
	{
		setMainCondition(HITTED);
	}
}

void skeleton::setMainCondition(MONSTER_MAINCONDITION mainCondition)
{
	if (_mainCondition != mainCondition && _subCondition != ATTACK && _mainCondition != HITTED && _mainCondition != DIE)
	{
		_mainCondition = mainCondition;
		if(_mainCondition != DYINGOUT)
		setCondition();
	}
}
void skeleton::setSubCondition(MONSTER_SUBCONDITION subCondition)	
{
	if (_subCondition != subCondition && _mainCondition != HITTED)
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
	case HITTED:
		switch (_subCondition)
		{
		case LAND:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_MOVE");
			else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_MOVE");
			_sumGravity = 0;
			break;
		case FALL:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_MOVE");
			else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_MOVE");
			break;
		}
		_sumNuckBack = 10;
	break;
	case DIE:
			if (_isRight)
				_ani = KEYANIMANAGER->findAnimation("SKELETON_RIGHT_DIE");
			else
				_ani = KEYANIMANAGER->findAnimation("SKELETON_LEFT_DIE");
			_sumGravity = 0;
	break;
	}

	if (_subCondition == ATTACK &&_mainCondition != DIE)
	{
		if (_isRight)
		{
			_imageRc = RectMake(_leftX + _width / 2 - _image->getFrameWidth() / 2, _topY - 40, _image->getFrameWidth(), _image->getFrameHeight());
			_collisionRc = RectMake(_leftX, _topY, _imageRc.right - _leftX, _height);
		}
		else
		{
			_imageRc = RectMake(_leftX + _width / 2 - _image->getFrameWidth() / 2, _topY - 40, _image->getFrameWidth(), _image->getFrameHeight());
			_collisionRc = RectMake(_leftX + _width / 2 - _image->getFrameWidth() / 2, _topY, _imageRc.right - _leftX, _height);

		}
	}
	else
	{
		_imageRc = RectMake(_leftX + _width / 2 - _image->getFrameWidth() / 2, _topY - 40, _image->getFrameWidth(), _image->getFrameHeight());
		_collisionRc = RectMake(_leftX, _topY, _width, _height);
	}
	 	_ani->start();
}

void skeleton::changeDirection()
{
	if(_mainCondition != HITTED)
	enemy::changeDirection();
}

void skeleton::attackReturn(void * obj)
{
	enemy* e = (enemy*)obj;

	e->setSubCondition(LAND);
}

void skeleton::dieReturn(void * obj)
{
	enemy* e = (enemy*)obj;

	e->setMainCondition(DYINGOUT);
}
