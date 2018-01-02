#include "stdafx.h"
#include "bullet.h"


bullet::bullet()
{
}


bullet::~bullet()
{
}

HRESULT bullet::init(const char* imageName, int bulletMax, float range)
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;
	return S_OK;
}

void bullet::release(void)
{
}

void bullet::update(void)
{
	move();
}

void bullet::render(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(), _viBullet->rc.left, _viBullet->rc.top,_viBullet->bulletImage->getFrameX(),_viBullet->bulletImage->getFrameY());
	}
}

void bullet::fire(float x, float y, float angle, float speed)
{
	if (_bulletMax < _vBullet.size()) return;

	tagbullet bullet;
	ZeroMemory(&bullet, sizeof(tagbullet));
	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.speed = speed;
	bullet.radius = bullet.bulletImage->getFrameWidth() / 2;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.angle = angle;

	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());

	_vBullet.push_back(bullet);
}

void bullet::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed;

		
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());

		if (_range < getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void bullet::removeBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}
