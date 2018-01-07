#include "stdafx.h"
#include "waterGirl.h"


waterGirl::waterGirl()
{
}


waterGirl::~waterGirl()
{
}

void waterGirl::Move()
{
	count++;
	if (_isRight)
	{
		crrenty = 0;
		_imgrc.left  += 1;
		_imgrc.right += 1;
		if (count % 10 == 0) {
			if (crrentx < 1) crrentx++;
			else crrentx = 0;
		}
	}
	else 
	{
		crrenty = 1;
		_imgrc.left -= 1;
		_imgrc.right -= 1;
		
		if (count % 10 == 0) {
			if (crrentx < 1) crrentx++;
			else crrentx = 0;
		}
	}
	
	if (_imgrc.left == 6685)
	{
		_isRight = false;
	}
	else if (_imgrc.right == 6085)
	{
		_isRight = true;
	}
	RC =RectMake(_imgrc.left , _imgrc.top + 45, _Npcimage->getFrameWidth(), 5);
	sprintf_s(str, "crrentx : %d", crrentx);
}

void waterGirl::render()
{
	
	IMAGEMANAGER->findImage(_imgName)->frameRender(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y , crrentx, crrenty);
	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePoint(RC).x, CAMERAMANAGER->CameraRelativePoint(RC).y, _Npcimage->getFrameWidth(), 5);
	TextOut(getMemDC(), 500, 500, str, strlen(str));
	
}

