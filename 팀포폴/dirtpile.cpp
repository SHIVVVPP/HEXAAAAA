#include "stdafx.h"
#include "dirtpile.h"


dirtpile::dirtpile()
{
	_type = TYPE_DIRTPILE;
	_move = false;
	_hang = false;

	_picked = false;
	_canLand = false;
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
	
	_x = x;
	_y = y;

	_rc = RectMake(_x, _y, IMAGEMANAGER->findImage("dirtpile")->getFrameWidth(), IMAGEMANAGER->findImage("dirtpile")->getFrameHeight());

	return S_OK;
}

void dirtpile::update()
{

}

void dirtpile::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
		Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	IMAGEMANAGER->findImage("dirtpile")->aniRender(getMemDC(), _x, _y, _objAni);
}
