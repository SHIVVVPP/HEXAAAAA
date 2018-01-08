#include "stdafx.h"
#include "bagFella.h"



bagFella::bagFella()
{
}


bagFella::~bagFella()
{
}

void bagFella::Move()
{
	if (!_istolk) {
		if (_imgrc.right > 4215) {
			_imgrc.left -= 2;
			_imgrc.right -= 2;
		}
		else 
		{
			visible = false;
		}
	}
}

void bagFella::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1)) {
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());

	}
	//	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());
	if(visible)_Npcimage->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y, _aniNpc);

	tolkdrow();
}
