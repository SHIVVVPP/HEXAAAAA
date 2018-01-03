#include "stdafx.h"
#include "stage.h"
#include "player.h"

stage::stage()
{
}


stage::~stage()
{
}

HRESULT stage::init()
{
	setStageBackgroundInfo();

	_currentRoom = findRoomInfo("1");
	_prevRoom = findRoomInfo("1");
	CAMERAMANAGER->setStartBackground(0, 0);
	CAMERAMANAGER->setBackground(_currentRoom._leftX + _currentRoom._width, _currentRoom._topY + _currentRoom._height);


	_rc = RectMakeCenter(_currentRoom._leftX + _currentRoom._width / 2, _currentRoom._topY + _currentRoom._height / 2, 50, 50);
	CAMERAMANAGER->setCameraCondition(false, CAMERA_AIMING);
	CAMERAMANAGER->setCameraCondition(true, CAMERA_AIMING);
	CAMERAMANAGER->setCameraAim(&_rc);

	




	setCameraObject();
	return S_OK;
}

void stage::release()
{
}

void stage::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += 6;
		_rc.right += 6;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= 6;
		_rc.right -= 6;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_rc.top += 6;
		_rc.bottom += 6;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_rc.top -= 6;
		_rc.bottom -= 6;
	}

	string c_col = CAMERAMANAGER->cameraOCollision(_rc,_currentRoom.myKey);
	if (c_col == "empty") {}
	else 
	{
		_prevRoom = _currentRoom;
		_currentRoom = _mRoom.find(c_col)->second;
	}
	//_player->update();
}

void stage::render()
{
	_currentRoom._roomImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_currentRoom._leftX), CAMERAMANAGER->CameraRelativePointY(_currentRoom._topY));
	
	for (int i = 0; i < _currentRoom._vConnectedRoom.size(); i++)
	{
		tagRoomInfo temp = _mRoom.find(_currentRoom._vConnectedRoom[i])->second;
		temp._roomImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(temp._leftX), CAMERAMANAGER->CameraRelativePointY(temp._topY));
	}
	
	//_prevRoom._roomImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_prevRoom._leftX), CAMERAMANAGER->CameraRelativePointY(_prevRoom._topY));
	_player->render();
	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), 50, 50);

	char str[128];

	sprintf(str, "mouse point X %d, Y %d", _ptMouse.x+CAMERAMANAGER->getCameraPoint().x, _ptMouse.y + CAMERAMANAGER->getCameraPoint().y);
	TextOut(getMemDC(), WINSIZEX / 2, 0, str, strlen(str));
	sprintf(str, "rc lt %d %d, rb %d %d", _rc.left, _rc.top, _rc.right, _rc.bottom);
	TextOut(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top - 20), str, strlen(str));
	sprintf(str, "current Room lt %d %d rb %d %d", _currentRoom._leftX, _currentRoom._topY, _currentRoom._leftX + _currentRoom._width, _currentRoom._topY + _currentRoom._height);
	TextOut(getMemDC(), 0, 0, str, strlen(str));

	CAMERAMANAGER->cameraObjectRender(getMemDC());
}


void stage::setStageBackgroundInfo()
{
	// 1~3 0,2732 ->


	tagRoomInfo temp;
	temp._roomImage = IMAGEMANAGER->findImage("back1");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack1");
	temp._leftX = 0;
	temp._topY = 2732;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "2" };
	temp.myKey = "1";
	_mRoom.insert(make_pair("1", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back2");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack2");
	temp._leftX = IMAGEMANAGER->findImage("back1")->getWidth();
	temp._topY = 2732;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "2" ,"3"};
	temp.myKey = "2";
	_mRoom.insert(make_pair("2", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back3");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack3");
	temp._leftX = IMAGEMANAGER->findImage("back1")->getWidth() + IMAGEMANAGER->findImage("back2")->getWidth();
	temp._topY = 2732;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "2","4" };
	temp.myKey = "3";
	_mRoom.insert(make_pair("3", temp));

	// 4~6 

	temp._roomImage = IMAGEMANAGER->findImage("back4");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack4");
	temp._leftX = 7819;
	temp._topY = 1901;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "3","5" };
	temp.myKey = "4";
	_mRoom.insert(make_pair("4", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back5");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack5");
	temp._leftX = 7819 + IMAGEMANAGER->findImage("back4")->getWidth();
	temp._topY = 1901;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "4","6" };
	temp.myKey = "5";
	_mRoom.insert(make_pair("5", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back6");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack6");
	temp._leftX = 7819 + IMAGEMANAGER->findImage("back4")->getWidth() + IMAGEMANAGER->findImage("back5")->getWidth();
	temp._topY = 1901;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "5","7" };
	temp.myKey = "6";
	_mRoom.insert(make_pair("6", temp));


	//7~8 7819 1901~4391 v


	temp._roomImage = IMAGEMANAGER->findImage("back7");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack7");
	temp._leftX = 11019;
	temp._topY = 4391;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "6","8" };
	temp.myKey = "7";
	_mRoom.insert(make_pair("7", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back8");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack8");
	temp._leftX = 11019;
	temp._topY = 4391 + IMAGEMANAGER->findImage("back7")->getHeight();
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "7","801","9" };
	temp.myKey = "8";
	_mRoom.insert(make_pair("8", temp));

	// 9~10  11019,4391

	temp._roomImage = IMAGEMANAGER->findImage("back8_left");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack8_left");
	temp._leftX = 9419;
	temp._topY = 4391;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "8" };
	temp.myKey = "801";
	_mRoom.insert(make_pair("801", temp));


	temp._roomImage = IMAGEMANAGER->findImage("back9");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack9");
	temp._leftX = 9419 + IMAGEMANAGER->findImage("back8")->getWidth();
	temp._topY = 4391;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "8","9" };
	temp.myKey = "9";
	_mRoom.insert(make_pair("9", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back10");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack10");
	temp._leftX = 9419 + IMAGEMANAGER->findImage("back8")->getWidth() + IMAGEMANAGER->findImage("back9")->getWidth();
	temp._topY = 4391;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "9","10" };
	temp.myKey = "10";
	_mRoom.insert(make_pair("10", temp));



	// 11~14    15819 1901

	temp._roomImage = IMAGEMANAGER->findImage("back11");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack11");
	temp._leftX = 15819;
	temp._topY = 1901;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "10","12" };
	temp.myKey = "11";
	_mRoom.insert(make_pair("11", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back12");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack12");
	temp._leftX = 15819 + IMAGEMANAGER->findImage("back11")->getWidth();
	temp._topY = 1901;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "11","1101","13" };
	temp.myKey = "12";
	_mRoom.insert(make_pair("12", temp));


	temp._roomImage = IMAGEMANAGER->findImage("back13");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack13");
	temp._leftX = 15819 + IMAGEMANAGER->findImage("back11")->getWidth() + IMAGEMANAGER->findImage("back12")->getWidth();
	temp._topY = 1901;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "12","14" };
	temp.myKey = "13";
	_mRoom.insert(make_pair("13", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back14");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack14");
	temp._leftX = 15819 + IMAGEMANAGER->findImage("back11")->getWidth() + IMAGEMANAGER->findImage("back12")->getWidth() + IMAGEMANAGER->findImage("back13")->getWidth();
	temp._topY = 1901;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "13","15" };
	temp.myKey = "14";
	_mRoom.insert(make_pair("14", temp));


	// 11 right 17419 3561
	temp._roomImage = IMAGEMANAGER->findImage("back11_right");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack11_right");
	temp._leftX = 17419;
	temp._topY = 3561;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "11" };
	temp.myKey = "1101";
	_mRoom.insert(make_pair("1101", temp));


	// 15~boss 22219 240

	temp._roomImage = IMAGEMANAGER->findImage("back15");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack15");
	temp._leftX = 22219;
	temp._topY = 240;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "14","1501","16" };
	temp.myKey = "15";
	_mRoom.insert(make_pair("15", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back15_left");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack15_left");
	temp._leftX = 22219 - IMAGEMANAGER->findImage("back15_left")->getWidth();
	temp._topY = 240;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp.myKey = "1501";
	_mRoom.insert(make_pair("1501", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back16");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack16");
	temp._leftX = 22219 + IMAGEMANAGER->findImage("back16")->getWidth();
	temp._topY = 240;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "15","17" };
	temp.myKey = "16";
	_mRoom.insert(make_pair("16", temp));

	temp._roomImage = IMAGEMANAGER->findImage("backBoss");
	temp._pixelColImage = IMAGEMANAGER->findImage("colbackBoss");
	temp._leftX = 22219 + IMAGEMANAGER->findImage("back16")->getWidth() + IMAGEMANAGER->findImage("backBoss")->getWidth();
	temp._topY = 240;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "16" };
	temp.myKey = "17";
	_mRoom.insert(make_pair("17", temp));
}

tagRoomInfo stage::findRoomInfo(string strkey)
{
	miRoom key = _mRoom.find(strkey);

	return key->second;
}

void stage::setCameraObject()
{
	
	//1->2
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(6215, 2980, 20, 480),
	{ 0,6219 }, { 6219,6219 + WINSIZEX }, &_rc, true,"2");

	
}
