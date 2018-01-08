#include "stdafx.h"
#include "deerLady.h"


deerLady::deerLady()
{
}


deerLady::~deerLady()
{
}

void deerLady::Move()
{
	count++;
	if (!_istolk) {
		if (count % 10 == 0) {
			if (crrentx < 1) crrentx++;
			else crrentx = 0;
		}
		if (!_istolk) {
			if (_imgrc.left < 2550) {
				_imgrc.left += 2;
				_imgrc.right += 2;
			}
			else {
				visible = false;
			}
		}
	}
}

void deerLady::render()
{
	if(visible)IMAGEMANAGER->findImage(_imgName)->frameRender(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y, crrentx, crrenty);
	tolkdrow();
}
