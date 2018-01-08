#include "stdafx.h"
#include "dirtpile.h"


dirtpile::dirtpile()
{
	_type = TYPE_DIRTPILE;
	_move = false;
	_hang = false;

	_picked = false;
	_canLand = false;
	_canHit = false;
}


dirtpile::~dirtpile()
{
}

HRESULT dirtpile::init(int x, int y)
{
	_objAni = new animation;
	_objAni->init(IMAGEMANAGER->findImage("dirtpile")->getWidth(), IMAGEMANAGER->findImage("dirtpile")->getHeight(),
				  IMAGEMANAGER->findImage("dirtpile")->getFrameWidth(), IMAGEMANAGER->findImage("dirtpile")->getFrameHeight());
	_objAni->setDefPlayFrame(false, false);
	_objAni->setFPS(1);
	_leftX = x;
	_topY = y;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("dirtpile")->getFrameWidth(), IMAGEMANAGER->findImage("dirtpile")->getFrameHeight());

	return S_OK;
}

void dirtpile::update()
{
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("dirtpile")->getFrameWidth(), IMAGEMANAGER->findImage("dirtpile")->getFrameHeight());

}

void dirtpile::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("dirtpile")->getFrameWidth(), IMAGEMANAGER->findImage("dirtpile")->getFrameHeight());
	}

	IMAGEMANAGER->findImage("dirtpile")->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY), _objAni);
}
