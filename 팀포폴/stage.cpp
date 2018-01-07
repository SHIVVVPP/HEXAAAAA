#include "stdafx.h"
#include "stage.h"
#include "player.h"
#include "ui.h"
#include "objectManager.h"
#include "enemyManager.h"

stage::stage()
{
}


stage::~stage()
{
}

HRESULT stage::init()
{
	setStageBackgroundInfo();

	_ui = new ui;
	_ui->init(UI_STAGE);

	_currentRoom = findRoomInfo("1");
	_prevRoom = findRoomInfo("1");
	CAMERAMANAGER->setStartBackground(0, _currentRoom._topY);
	CAMERAMANAGER->setBackground(_currentRoom._leftX + _currentRoom._width, _currentRoom._topY + _currentRoom._height);


	_rc = RectMakeCenter(_currentRoom._leftX + _currentRoom._width / 2, _currentRoom._topY + _currentRoom._height / 2, 50, 50);
	CAMERAMANAGER->setCameraCondition(false, CAMERA_AIMING);
	CAMERAMANAGER->setCameraCondition(true, CAMERA_AIMING);
	CAMERAMANAGER->setCameraAim(_player->getPlayerRect());

	_player->setPlayerX(_currentRoom._leftX + _currentRoom._width / 2);
	_player->setPlayerY(_currentRoom._topY + _currentRoom._height / 2);

	_objectManager = new objectManager;
	_objectManager->connectPlayer(_player);
	_objectManager->init();

	_enemyManager = new enemyManager;
	_enemyManager->LinkPlayer(_player);
	_enemyManager->LinkObjM(_objectManager);
	_enemyManager->init();

	//_changeSceneRc = RectMake(27008, 240, 20, 700);
	_changeSceneRc = RectMake(5000, 2800, 20, 700);

	Tool = new settingTool;
	Tool->init();

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
		_rc.left += 15;
		_rc.right += 15;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= 15;
		_rc.right -= 15;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_rc.top += 15;
		_rc.bottom += 15;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_rc.top -= 15;
		_rc.bottom -= 15;
	}
	
	string c_col = CAMERAMANAGER->cameraOCollision(*_player->getPlayerRect(),_currentRoom.myKey);
	if (c_col != "empty")
	{
			_currentRoom = _mRoom.find(c_col)->second;
	}
	//_player->update();
	_objectManager->update();
	_objectManager->player_object_collision();
	_enemyManager->setPixelColInfo(_currentRoom._pixelColImage, { _currentRoom._leftX,_currentRoom._topY });
	_enemyManager->update();
	_ui->update();
	
	if (_player->getPlayerMainCondition() != 7 && _player->getPlayerMainCondition() != 8 && _player->getPlayerMainCondition() != 9)
	{
		pixelCollison();
	}
	
	Tool->update();
	_player->getColMessage(_objectManager->player_object_collision());

	RECT temp;
	if (IntersectRect(&temp, _player->getPlayerRect(), &_changeSceneRc))
	{
		SCENEMANAGER->changeScene("마을", _player);
	}
}

void stage::render()
{
	
	for (int i = 0; i < _currentRoom._vConnectedRoom.size(); i++)
	{
		tagRoomInfo temp = _mRoom.find(_currentRoom._vConnectedRoom[i])->second;
		temp._roomImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(temp._leftX), CAMERAMANAGER->CameraRelativePointY(temp._topY));
	}
	
	_prevRoom._roomImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_prevRoom._leftX), CAMERAMANAGER->CameraRelativePointY(_prevRoom._topY));
	_currentRoom._roomImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_currentRoom._leftX), CAMERAMANAGER->CameraRelativePointY(_currentRoom._topY));
	_currentRoom._pixelColImage->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_currentRoom._leftX), CAMERAMANAGER->CameraRelativePointY(_currentRoom._topY));
	_player->render();

	_objectManager->render();
	_enemyManager->render();
	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), 50, 50);
	_ui->render();



	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;
	hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	hOldBrush = (HBRUSH)SelectObject(getMemDC(), hBrush);
	hOldPen = (HPEN)SelectObject(getMemDC(), hPen);
	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_currentRoom._leftX), CAMERAMANAGER->CameraRelativePointY(_currentRoom._topY), _currentRoom._width, _currentRoom._height);
	SelectObject(getMemDC(), hOldPen);
	SelectObject(getMemDC(), hOldBrush);
	DeleteObject(hBrush);
	DeleteObject(hPen);

	char str[128];
	
	sprintf(str, "mouse point X %d, Y %d", _ptMouse.x + CAMERAMANAGER->getCameraPoint().x, _ptMouse.y + CAMERAMANAGER->getCameraPoint().y);
	TextOut(getMemDC(), WINSIZEX / 2, 0, str, strlen(str));
	sprintf(str, "rc lt %d %d, rb %d %d", _rc.left, _rc.top, _rc.right, _rc.bottom);
	TextOut(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top - 20), str, strlen(str));
	sprintf(str, "current Room lt %d %d rb %d %d", _currentRoom._leftX, _currentRoom._topY, _currentRoom._leftX + _currentRoom._width, _currentRoom._topY + _currentRoom._height);
	TextOut(getMemDC(), 0, 0, str, strlen(str));

	CAMERAMANAGER->cameraObjectRender(getMemDC());
	Tool->render();
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
	temp._vConnectedRoom = {"1","3"};
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
	temp._topY = 2732;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "6","8" };
	temp.myKey = "7";
	_mRoom.insert(make_pair("7", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back8");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack8");
	temp._leftX = 11019;
	temp._topY = 2732 + IMAGEMANAGER->findImage("back7")->getHeight();
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "7","801","9" };
	temp.myKey = "8";
	_mRoom.insert(make_pair("8", temp));

	// 9~10  11019,4391

	temp._roomImage = IMAGEMANAGER->findImage("back8_left");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack8_left");
	temp._leftX = 9419;
	temp._topY = 4321;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "8" };
	temp.myKey = "801";
	_mRoom.insert(make_pair("801", temp));


	temp._roomImage = IMAGEMANAGER->findImage("back9");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack9");
	temp._leftX = 11019 + IMAGEMANAGER->findImage("back8")->getWidth();
	temp._topY = 4321;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "8","9" };
	temp.myKey = "9";
	_mRoom.insert(make_pair("9", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back10");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack10");
	temp._leftX = 11019 + IMAGEMANAGER->findImage("back8")->getWidth() + IMAGEMANAGER->findImage("back9")->getWidth();
	temp._topY = 4321;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "9","10" };
	temp.myKey = "10";
	_mRoom.insert(make_pair("10", temp));



	// 11~14    15819 1901

	temp._roomImage = IMAGEMANAGER->findImage("back11");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack11");
	temp._leftX = 15819;
	temp._topY = 1830;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "10","12" };
	temp.myKey = "11";
	_mRoom.insert(make_pair("11", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back12");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack12");
	temp._leftX = 15819 + IMAGEMANAGER->findImage("back11")->getWidth();
	temp._topY = 1830;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "11","1101","13" };
	temp.myKey = "12";
	_mRoom.insert(make_pair("12", temp));


	temp._roomImage = IMAGEMANAGER->findImage("back13");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack13");
	temp._leftX = 15819 + IMAGEMANAGER->findImage("back11")->getWidth() + IMAGEMANAGER->findImage("back12")->getWidth();
	temp._topY = 1830;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "12","14" };
	temp.myKey = "13";
	_mRoom.insert(make_pair("13", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back14");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack14");
	temp._leftX = 15819 + IMAGEMANAGER->findImage("back11")->getWidth() + IMAGEMANAGER->findImage("back12")->getWidth() + IMAGEMANAGER->findImage("back13")->getWidth();
	temp._topY = 1830;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "13","15" };
	temp.myKey = "14";
	_mRoom.insert(make_pair("14", temp));


	// 11 right 17419 3561
	temp._roomImage = IMAGEMANAGER->findImage("back11_right");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack11_right");
	temp._leftX = 17419;
	temp._topY = 3471;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "11" };
	temp.myKey = "1101";
	_mRoom.insert(make_pair("1101", temp));


	// 15~boss 22219 240

	temp._roomImage = IMAGEMANAGER->findImage("back15");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack15");
	temp._leftX = 22219;
	temp._topY = 169;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "14","1501","16" };
	temp.myKey = "15";
	_mRoom.insert(make_pair("15", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back15_left");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack15_left");
	temp._leftX = 22219 - IMAGEMANAGER->findImage("back15_left")->getWidth();
	temp._topY = 169;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp.myKey = "1501";
	_mRoom.insert(make_pair("1501", temp));

	temp._roomImage = IMAGEMANAGER->findImage("back16");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBack16");
	temp._leftX = 22219 + IMAGEMANAGER->findImage("back16")->getWidth();
	temp._topY = 169;
	temp._width = temp._roomImage->getWidth();
	temp._height = temp._roomImage->getHeight();
	temp._vConnectedRoom = { "15","17" };
	temp.myKey = "16";
	_mRoom.insert(make_pair("16", temp));

	temp._roomImage = IMAGEMANAGER->findImage("backBoss");
	temp._pixelColImage = IMAGEMANAGER->findImage("colBackBoss");
	temp._leftX = 22219 + IMAGEMANAGER->findImage("back16")->getWidth() + IMAGEMANAGER->findImage("backBoss")->getWidth();
	temp._topY = 169;
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
	RECT* rc = _player->getPlayerRect();
	//1->2
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(6215, 2980, 20, 480),
	{ 0,6219 }, { 6219,6219 + WINSIZEX }, rc, true, "2");

	//2->3 7811 2991
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(7811, 2994, 20, 480),
	{ 6219,6219 + WINSIZEX }, { 7819,7819 + WINSIZEX }, rc, true, "3");

	//3->4 사다리
	CAMERAMANAGER->addCameraObject(true, true, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(8955, 2735, 106, 20),
	{ 2732,2732 + WINSIZEY }, { 1901,1901+WINSIZEY }, rc, false, "4");

	//4->5 
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(9409, 1964, 20, 331),
	{ 7819,7819 + WINSIZEX }, { 9419,9419 + WINSIZEX }, rc, true, "5");

	//5->6
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(11008, 1962, 20, 728),
	{ 9419,9419 + WINSIZEX }, { 11019,11019 + WINSIZEX }, rc, true, "6");

	//6->7
	CAMERAMANAGER->addCameraObject(true, true, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(12356, 2794, 100, 20),
	 { 1901,1901 + WINSIZEY }, { 2732,2732 + WINSIZEY }, rc, true, "7");

	//7->8
	CAMERAMANAGER->addCameraObject(true, true, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(11333, 3626, 100, 20),
	{ 2732,2732 + WINSIZEY }, { 3632,3632 + WINSIZEY }, rc, true, "8");

	//8->8 under
	CAMERAMANAGER->addCameraObject(true, true, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(12361, 4220, 140, 20),
	{ 3632,3632 + WINSIZEY }, { 5221-WINSIZEY,5221 }, rc, true, "8");

	//8->8_LEFT
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(11010, 4889, 20, 228),
	{ 11019,12619 }, { 9419,11019 }, rc, false, "801");

	//8->9
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(12611, 4632, 20, 341),
	 { 11019,12619 }, { 12619,14219 }, rc, true, "9");

	//9~10
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(14210, 4387, 20, 714),
	{ 12619,14219 }, { 14219,15819 }, rc, true, "10");

	//10~11
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(15812, 4702, 20, 401),
	{ 14219,15819 }, { 15819,17419 }, rc, true, "11");

	//11->11 사다리
	CAMERAMANAGER->addCameraObject(true, true, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(17218, 4404, 80, 20),
	{ 4321,5221 }, { 4371-WINSIZEY,4371 }, rc, false, "11");

	//11->1101
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(17410, 3803, 20, 215),
	{ 15819,17419 }, { 17419,19722 }, rc, true, "1101");

	//11->11 사다리
	CAMERAMANAGER->addCameraObject(true, true, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(15819, 3567, 80, 20),
	{ 4371 - WINSIZEY,4371 }, { 3577 - WINSIZEY, 3577 }, rc, false, "11");

	//11->11 사다리2
	CAMERAMANAGER->addCameraObject(true, true, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(16198, 2668, 80, 20),
	{ 3577 - WINSIZEY, 3577 }, { 2730 - WINSIZEY, 2730 }, rc, false, "11");

	CAMERAMANAGER->addCameraObject(true, true, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(16901, 2668, 80, 20),
	{ 3577 - WINSIZEY, 3577 }, { 2730 - WINSIZEY, 2730 }, rc, false, "11");

	//11->12
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(17411, 1896, 20, 462),
	{ 15819,17419 }, { 17419,19019 }, rc, true, "12");

	//12->13
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(19010, 1898, 20, 520),
	{ 17419,19019 }, { 19019,20619 }, rc, true, "13");

	//13->14
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(20612, 1898, 20, 322),
	{ 19019,20619 }, { 20619,22219 }, rc, true, "14");

	//14->15
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(22210, 1910, 20, 633),
	{ 20619,22219 }, { 22219,23819 }, rc, true, "15");

	//15 사다리
	CAMERAMANAGER->addCameraObject(true, true, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(23691, 1820, 80, 20),
	{ 2730 - WINSIZEY, 2730 }, { 999, 1899 }, rc, false, "15");

	CAMERAMANAGER->addCameraObject(true, true, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(22737, 1059, 80, 20),
	{ 999, 1899 }, { 169, 1069 }, rc, false, "15");

	//15 1501
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(22219, 232, 20, 332),
	 { 22219,23819 }, { 20236,22219 }, rc, false, "1501");
	

	//15->16
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(23807, 232, 20, 718),
	{ 22219,23819 }, { 23819,25419 }, rc, true, "16");

	//16->boss
	CAMERAMANAGER->addCameraObject(false, false, C_OBJECT_MOVE, CAMERA_AIMING, RectMake(25407, 232, 20, 718),
	{ 23819,25419 }, { 25419,27019 }, rc, true, "17");

}



void stage::pixelCollison()
{
	COLORREF color;
	int r, g, b;

	// 머리 충돌판정
	
	if (_player->getJumpPower() > 0)
	{
		_player->setProbeY(_player->getPlayerRect()->top - _currentRoom._topY);
	
		color = GetPixel(_currentRoom._pixelColImage->getMemDC(), _player->getPlayerRect()->left - _currentRoom._leftX, _player->getPlayerRect()->top-_currentRoom._topY);
	
		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);
	
		//	if ()
	}
	
	if (_player->getOffPicxel() == false)
	{
		if (_player->getJumpPower() <= 0)
		{
			_player->setProbeY(_player->getPlayerRect()->bottom - _currentRoom._topY);
			bool k = false;
			int a = 0;
			int b = 0;
			bool istop = false;
			for (int i = _player->getprobeY() + 30; i > _player->getprobeY() - 30; --i)
			{
				color = GetPixel(_currentRoom._pixelColImage->getMemDC(), (_player->getPlayerRect()->left + _player->getPlayerRect()->right) / 2 - _currentRoom._leftX, i);

				r = GetRValue(color);
				g = GetGValue(color);
				b = GetBValue(color);


				if (r == 0 && g == 255 && b == 0)
				{
					k = true;
					_player->setPlayerY(i - getHeight(*_player->getPlayerRect()) / 2 + _currentRoom._topY);
					a++;
				}
			}

			if (k)
			{
				_player->setIsJump(false);
				_player->setIsLand(true);

			}
			else
			{
				color = GetPixel(_currentRoom._pixelColImage->getMemDC(), (_player->getPlayerRect()->left + _player->getPlayerRect()->right) / 2 + _currentRoom._leftX, _player->getprobeY() + 1);
				r = GetRValue(color);
				g = GetGValue(color);
				b = GetBValue(color);

				color = GetPixel(_currentRoom._pixelColImage->getMemDC(), (_player->getPlayerRect()->left + _player->getPlayerRect()->right) / 2 - _currentRoom._leftX, _player->getprobeY() + 1);
				int r1 = GetRValue(color);
				int g1 = GetGValue(color);
				int b1 = GetBValue(color);


				_player->setIsJump(true);
				_player->setIsLand(false);
			}
		}
	}
	

	//벽충돌
	color = GetPixel(_currentRoom._pixelColImage->getMemDC(), _player->getPlayerRect()->left - _currentRoom._leftX, _player->getPlayerRect()->bottom - 10 - _currentRoom._topY);
	r = GetRValue(color);
	g = GetGValue(color);
	b = GetBValue(color);
	if ((r == 0 && g == 255 & b == 0))
	{
		int k = 0;
		for (int z = _player->getPlayerRect()->left - _currentRoom._leftX; z < _player->getPlayerX() - _currentRoom._leftX; z++)
		{
			color = GetPixel(_currentRoom._pixelColImage->getMemDC(),z, _player->getPlayerRect()->bottom - 10 - _currentRoom._topY);
			r = GetRValue(color);
			g = GetGValue(color);
			b = GetBValue(color);
			if ((r == 0 && g == 255 & b == 0))
			{
				k++;
			}
		}
		_player->setPlayerX(_player->getPlayerX() + k);
	}


	color = GetPixel(_currentRoom._pixelColImage->getMemDC(), _player->getPlayerRect()->right - _currentRoom._leftX, _player->getPlayerRect()->bottom - 10 - _currentRoom._topY);
	r = GetRValue(color);
	g = GetGValue(color);
	b = GetBValue(color);
	if ((r == 0 && g == 255 & b == 0))
	{
		int k = 0;
		for (int z = _player->getPlayerRect()->right - _currentRoom._leftX; z > _player->getPlayerX() - _currentRoom._leftX-1; z--)
		{
			color = GetPixel(_currentRoom._pixelColImage->getMemDC(), z, _player->getPlayerRect()->bottom - 10 - _currentRoom._topY);
			r = GetRValue(color);
			g = GetGValue(color);
			b = GetBValue(color);
			if ((r == 0 && g == 255 & b == 0))
			{
				k++;
			}
			else break;
		}
		_player->setPlayerX(_player->getPlayerX() - k);
	}

	
}

void stage::CreateGem(void* obj)
{

}
