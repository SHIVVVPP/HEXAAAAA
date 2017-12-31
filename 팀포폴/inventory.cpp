#include "stdafx.h"
#include "inventory.h"


inventory::inventory()
{
}


inventory::~inventory()
{
}

HRESULT inventory::init()
{
	_invenRelic = new inventoryRelic;
	_invenGear = new inventoryGear;
	_invenImage = IMAGEMANAGER->findImage("invenOpen");
	_invenImage->setX(WINSIZEX / 2);
	_invenImage->setY(WINSIZEY / 2);

	_cursor = IMAGEMANAGER->findImage("cursor");
	_center.x = _cursor->getCenterX();
	_center.y = _cursor->getCenterY();
	_cursorRect = RectMakeCenter(_center.x, _center.y, _cursor->getWidth(), _cursor->getHeight());
	_invenani = new animation;
	_invenani->init(_invenImage->getWidth(), _invenImage->getHeight(), _invenImage->getFrameWidth(), _invenImage->getFrameHeight());
	_invenani->setDefPlayFrame(false, false);
	_invenani->start();
	_invenani->setFPS(1);

	_cursorPoint = CURSORPOINT0;
	_cursorAlpha = 255;
	_count = 0;
	_relic = true;

	_checkRect = RectMakeCenter(1400, 500, 150, 150);

	return S_OK;
}



void inventory::release()
{

}

void inventory::update()
{
	_invenani->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);
	_count++;
	if (_invenani->getPlayIndex() >= _invenImage->getMaxFrameX())
	{
		_invenImage = IMAGEMANAGER->findImage("inventory");
		_invenImage->setX(WINSIZEX / 2 - 550);
		_invenImage->setY(WINSIZEY / 2 - 350);
		if (_invenani->getPlayIndex() >= 3)_invenani->stop();
	}

	if (KEYMANAGER->isOnceKeyDown('J'))
	{
		if (_invenani->getPlayIndex() == 0 || !_invenani->getPlayIndex() == 1)
		{
			_invenani->setPlayIndex(1);  //프레임넘버 바꾸기
			_cursorPoint = CURSORPOINT0; //커서위치 0으로(첫번째 위치로) 다시 저장함.
			_relic = false;

			for (_invenRelic->getViRelic() = _invenRelic->getVRelic().begin(); _invenRelic->getViRelic() != _invenRelic->getVRelic().end(); ++_invenRelic->getViRelic())
			{
				_invenRelic->getViRelic()->_isRelic = false;
			}

			for (_invenGear->getViGear() = _invenGear->getVGear().begin(); _invenGear->getViGear() != _invenGear->getVGear().end(); ++_invenGear->getViGear())
			{
				_invenGear->getViGear()->_isGear = true;
			}
		}
		else if (_invenani->getPlayIndex() == 1 || !_invenani->getPlayIndex() == 0)
		{
			_invenani->setPlayIndex(0);  //프레임넘버 바꾸기
			_cursorPoint = CURSORPOINT0; //커서위치 0으로(첫번째 위치로) 다시 저장함. 
			_relic = true;
			for (_invenRelic->getViRelic() = _invenRelic->getVRelic().begin(); _invenRelic->getViRelic() != _invenRelic->getVRelic().end(); ++_invenRelic->getViRelic())
			{
				_invenRelic->getViRelic()->_isRelic = true;
			}

			for (_invenGear->getViGear() = _invenGear->getVGear().begin(); _invenGear->getViGear() != _invenGear->getVGear().end(); ++_invenGear->getViGear())
			{
				_invenGear->getViGear()->_isGear = false;
			}
		}
	}

	if (_cursorAlpha >= 255 && _count % 30 == 0) //커서 깜빡임
	{
		_cursorAlpha = 0;
	}
	else if (_cursorAlpha == 0 && _count % 60 == 0) _cursorAlpha = 255;

	if (PtInRect(&_checkRect, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_invenRelic->init("firelod", Relics0, true, true);
			_invenRelic->init("tangtangball", Relics1, true, true);
			_invenRelic->init("fishingrod", Relics2, true, true);

			_invenGear->init("shovel", Gear0, false, true);
			_invenGear->init("armor", Gear1, false, true);
			_invenGear->init("healthcap", Gear2, false, true);
			_invenGear->init("invenMealTickets", Gear3, false, true);
			_invenGear->init("invenMusicSheet", Gear4, false, true);
		}
	}

	cursorMove();
}

void inventory::render()
{
	_invenImage->aniRender(getMemDC(), _invenImage->getX(), _invenImage->getY(), _invenani);
	if (KEYMANAGER->isToggleKey(VK_F1)) RectangleMake(getMemDC(), _center.x, _center.y, _cursor->getWidth(), _cursor->getHeight());
	_cursor->alphaRender(getMemDC(), _center.x, _center.y, _cursorAlpha);

	Rectangle(getMemDC(), _checkRect.left, _checkRect.top, _checkRect.right, _checkRect.bottom);

	_invenRelic->render();
	_invenGear->render();
	draw();
}

void inventory::cursorMove()
{
	if (_relic) //유물창인 경우.
	{
		switch (_cursorPoint)
		{
		case CURSORPOINT0:
			_center.x = 300;
			_center.y = 250;
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) _cursorPoint = CURSORPOINT5;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT1;
			break;
		case CURSORPOINT1:
			_center.x = 450;
			_center.y = 250;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) _cursorPoint = CURSORPOINT0;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT2;
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) _cursorPoint = CURSORPOINT6;
			break;
		case CURSORPOINT2:
			_center.x = 600;
			_center.y = 250;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) _cursorPoint = CURSORPOINT1;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT3;
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) _cursorPoint = CURSORPOINT7;
			break;
		case CURSORPOINT3:
			_center.x = 750;
			_center.y = 250;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) _cursorPoint = CURSORPOINT2;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT4;
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) _cursorPoint = CURSORPOINT8;
			break;
		case CURSORPOINT4:
			_center.x = 900;
			_center.y = 250;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) _cursorPoint = CURSORPOINT3;
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) _cursorPoint = CURSORPOINT9;
			break;
		case CURSORPOINT5:
			_center.x = 300;
			_center.y = 380;
			if (KEYMANAGER->isOnceKeyDown(VK_UP)) _cursorPoint = CURSORPOINT0;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT6;
			break;
		case CURSORPOINT6:
			_center.x = 450;
			_center.y = 380;
			if (KEYMANAGER->isOnceKeyDown(VK_UP)) _cursorPoint = CURSORPOINT1;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) _cursorPoint = CURSORPOINT5;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT7;
			break;
		case CURSORPOINT7:
			_center.x = 600;
			_center.y = 380;
			if (KEYMANAGER->isOnceKeyDown(VK_UP)) _cursorPoint = CURSORPOINT2;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) _cursorPoint = CURSORPOINT6;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT8;
			break;
		case CURSORPOINT8:
			_center.x = 750;
			_center.y = 380;
			if (KEYMANAGER->isOnceKeyDown(VK_UP)) _cursorPoint = CURSORPOINT3;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) _cursorPoint = CURSORPOINT7;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))_cursorPoint = CURSORPOINT9;
			break;
		case CURSORPOINT9:
			_center.x = 900;
			_center.y = 380;
			if (KEYMANAGER->isOnceKeyDown(VK_UP)) _cursorPoint = CURSORPOINT4;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))_cursorPoint = CURSORPOINT8;
			break;
		}
	}
	if (!_relic) //장비창인 경우.
	{
		switch (_cursorPoint)
		{
		case CURSORPOINT0:
			_center.x = 300;
			_center.y = 280;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT1;
			break;
		case CURSORPOINT1:
			_center.x = 450;
			_center.y = 280;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))   _cursorPoint = CURSORPOINT0;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT2;
			break;
		case CURSORPOINT2:
			_center.x = 600;
			_center.y = 280;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))  _cursorPoint = CURSORPOINT1;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT3;
			break;
		case CURSORPOINT3:
			_center.x = 750;
			_center.y = 280;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))  _cursorPoint = CURSORPOINT2;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT4;
			break;
		case CURSORPOINT4:
			_center.x = 900;
			_center.y = 280;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))  _cursorPoint = CURSORPOINT3;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _cursorPoint = CURSORPOINT5;
			break;
		case CURSORPOINT5:
			_center.x = 1050;
			_center.y = 280;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) _cursorPoint = CURSORPOINT4;
		}
	}
	_cursorRect = RectMakeCenter(_center.x, _center.y, _cursor->getWidth(), _cursor->getHeight());
}

void inventory::draw()
{
	if (_relic)
	{
		for (_invenRelic->getViRelic() = _invenRelic->getVRelic().begin(); _invenRelic->getViRelic() != _invenRelic->getVRelic().end(); ++_invenRelic->getViRelic())
		{
			if (_invenRelic->getViRelic()->_isRelic == true)IMAGEMANAGER->findImage("potion")->render(getMemDC(), 700, 730);
		}
	
		switch (_cursorPoint)
		{
		case CURSORPOINT0:
			for (_invenRelic->getViRelic() = _invenRelic->getVRelic().begin(); _invenRelic->getViRelic() != _invenRelic->getVRelic().end(); ++_invenRelic->getViRelic())
			{
				SetTextColor(getMemDC(), RGB(125, 125, 255));
				if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/firelod.txt", getMemDC(), 370, 600, 800, 100, 10);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/firelodex.txt", getMemDC(), 380, 650, 800, 100, 22);
	
				if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/firelodmana.txt", getMemDC(), 370, 740, 800, 100, 2);
			}
			break;
		case CURSORPOINT1:
			for (_invenRelic->getViRelic() = _invenRelic->getVRelic().begin(); _invenRelic->getViRelic() != _invenRelic->getVRelic().end(); ++_invenRelic->getViRelic())
			{
				SetTextColor(getMemDC(), RGB(125, 125, 255));
				if (_invenRelic->getViRelic()->_isRelic == true && Relics1)TXTDATA->render("./text/tangtangball.txt", getMemDC(), 370, 600, 800, 200, 13);
	
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/tangtangballex.txt", getMemDC(), 380, 650, 800, 200, 37);
				if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/tangtangballmana.txt", getMemDC(), 370, 740, 800, 200, 2);
			}
			break;
		case CURSORPOINT2:
			for (_invenRelic->getViRelic() = _invenRelic->getVRelic().begin(); _invenRelic->getViRelic() != _invenRelic->getVRelic().end(); ++_invenRelic->getViRelic())
			{
				SetTextColor(getMemDC(), RGB(125, 125, 255));
				if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/rod.txt", getMemDC(), 370, 600, 800, 200, 12);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/rodex.txt", getMemDC(), 380, 650, 800, 200, 37);
				if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/rodmana.txt", getMemDC(), 370, 740, 800, 200, 2);
			}
			break;
		}
	}

	//if (_relic)
	//{
	//	for (_invenRelic->getViRelic() = _invenRelic->getVRelic().begin(); _invenRelic->getViRelic() != _invenRelic->getVRelic().end(); ++_invenRelic->getViRelic())
	//	{
	//		if (_invenRelic->getViRelic()->_isRelic == true)IMAGEMANAGER->findImage("potion")->render(getMemDC(), 700, 730);
	//	}
	//
	//	for (_invenRelic->getViRelic() = _invenRelic->getVRelic().begin(); _invenRelic->getViRelic() != _invenRelic->getVRelic().end(); ++_invenRelic->getViRelic())
	//	{
	//		switch (_invenRelic->getViRelic()->_itemNum && _cursorPoint)
	//		{
	//		case Relics0: case CURSORPOINT0:
	//			SetTextColor(getMemDC(), RGB(125, 125, 255));
	//			if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/firelod.txt", getMemDC(), 370, 600, 800, 100, 10);
	//			SetTextColor(getMemDC(), RGB(255, 255, 255));
	//			if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/firelodex.txt", getMemDC(), 380, 650, 800, 100, 22);
	//
	//			if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/firelodmana.txt", getMemDC(), 370, 740, 800, 100, 2);
	//			break;
	//		case Relics1: case CURSORPOINT1:
	//			SetTextColor(getMemDC(), RGB(125, 125, 255));
	//			if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/tangtangball.txt", getMemDC(), 370, 600, 800, 200, 13);
	//
	//			SetTextColor(getMemDC(), RGB(255, 255, 255));
	//			if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/tangtangballex.txt", getMemDC(), 380, 650, 800, 200, 37);
	//			if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/tangtangballmana.txt", getMemDC(), 370, 740, 800, 200, 2);
	//			break;
	//		case Relics2: case CURSORPOINT2:
	//			SetTextColor(getMemDC(), RGB(125, 125, 255));
	//			if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/rod.txt", getMemDC(), 370, 600, 800, 200, 12);
	//			SetTextColor(getMemDC(), RGB(255, 255, 255));
	//			if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/rodex.txt", getMemDC(), 380, 650, 800, 200, 37);
	//			if (_invenRelic->getViRelic()->_isRelic == true)TXTDATA->render("./text/rodmana.txt", getMemDC(), 370, 740, 800, 200, 2);
	//			break;
	//		}
	//	}
	//}

	if (!_relic)
	{
		for (_invenGear->getViGear() = _invenGear->getVGear().begin(); _invenGear->getViGear() != _invenGear->getVGear().end(); ++_invenGear->getViGear())
		{
			switch (_invenGear->getViGear()->_itemNum && _cursorPoint)
			{
			case Gear0 : case  CURSORPOINT0:
				SetTextColor(getMemDC(), RGB(125, 125, 255));
				if (_invenGear->getViGear()->_isGear == true) TXTDATA->render("./text/shovel.txt", getMemDC(), 370, 500, 800, 200, 12);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				if (_invenGear->getViGear()->_isGear == true) TXTDATA->render("./text/shovelex.txt", getMemDC(), 370, 550, 800, 200, 52);
				break;
			case Gear1: case CURSORPOINT1:
				SetTextColor(getMemDC(), RGB(125, 125, 255));
				if (_invenGear->getViGear()->_isGear == true) TXTDATA->render("./text/armor.txt", getMemDC(), 370, 500, 800, 200, 14);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				if (_invenGear->getViGear()->_isGear == true) TXTDATA->render("./text/armorex.txt", getMemDC(), 370, 550, 800, 200, 40);
				break;
			case Gear2: case CURSORPOINT2:
				SetTextColor(getMemDC(), RGB(125, 125, 255));
				if (_invenGear->getViGear()->_isGear == true) TXTDATA->render("./text/shovel.txt", getMemDC(), 370, 500, 800, 200, 12);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				if (_invenGear->getViGear()->_isGear == true) TXTDATA->render("./text/shovelex.txt", getMemDC(), 370, 550, 800, 200, 52);
				break;
			//case CURSORPOINT2:
			//	break;
			//case CURSORPOINT3:
			//	break;
			//case CURSORPOINT4:
			//	break;
			}
		}
	}
}

void inventory::invenScene()
{
	SCENEMANAGER->changeScene("인벤토리");
}


inventoryRelic::inventoryRelic()
{
}

inventoryRelic::~inventoryRelic()
{
}

HRESULT inventoryRelic::init(const char* imageName, int itemNum, bool isrelic, bool isGet)
{
	_RelicName = imageName;
	_isGet = isGet;

	tagRelics Relic;
	ZeroMemory(&Relic, sizeof(tagRelics));
	Relic._image = IMAGEMANAGER->findImage(_RelicName);
	Relic._x = Relic._image->getCenterX();
	Relic._y = Relic._image->getCenterY();
	Relic._itemNum = itemNum;
	Relic._isRelic = isrelic;
	Relic._rc = RectMake(Relic._x, Relic._y, Relic._image->getWidth() / 2, Relic._image->getHeight() / 2);

	_vRelic.push_back(Relic);
	return S_OK;
}

void inventoryRelic::release()
{
}

void inventoryRelic::update()
{
	
}

void inventoryRelic::render()
{
	for (_viRelic = _vRelic.begin(); _viRelic != _vRelic.end(); ++_viRelic)
	{
		switch (_viRelic->_itemNum)
		{
		case Relics0:
			_viRelic->_x = 300;
			_viRelic->_y = 250;
			break;
		case Relics1:
			_viRelic->_x = 450;
			_viRelic->_y = 250;
			break;
		case Relics2:
			_viRelic->_x = 600;
			_viRelic->_y = 250;
			break;
		}
		if (KEYMANAGER->isToggleKey(VK_F1))
		{
			if (_viRelic->_isRelic == true)RectangleMake(getMemDC(), _viRelic->_x + (_viRelic->_rc.right - _viRelic->_rc.left) / 2, _viRelic->_y + (_viRelic->_rc.bottom - _viRelic->_rc.top) / 2,
				_viRelic->_image->getWidth() / 2, _viRelic->_image->getHeight() / 2);

		}
		if (_viRelic->_isRelic == true) _viRelic->_image->render(getMemDC(), _viRelic->_x, _viRelic->_y);
	}
}

inventoryGear::inventoryGear()
{
}

inventoryGear::~inventoryGear()
{
}

HRESULT inventoryGear::init(const char * imageName, int itemNum, bool isGear, bool isGet)
{
	_GearName = imageName;
	_isGet = isGet;
	//_itemNum = itemNum;
	tagGear Gear;
	ZeroMemory(&Gear, sizeof(tagGear));
	Gear._image = IMAGEMANAGER->findImage(_GearName);
	Gear._x = Gear._image->getCenterX();
	Gear._y = Gear._image->getCenterY();
	Gear._itemNum = itemNum;
	Gear._isGear = isGear;
	Gear._rc = RectMake(Gear._x, Gear._y, Gear._image->getWidth() / 2, Gear._image->getHeight() / 2);

	_vGear.push_back(Gear);

	return S_OK;
}

void inventoryGear::release()
{
}

void inventoryGear::update()
{
}

void inventoryGear::render()
{
	for (_viGear = _vGear.begin(); _viGear != _vGear.end(); ++_viGear)
	{
		switch (_viGear->_itemNum)
		{
		case Gear0:
			_viGear->_x = 300;
			_viGear->_y = 280;
			break;
		//case Gear1:
		//	_viGear->_x = 450;
		//	_viGear->_y = 280;
		//	break;
		case Gear2:
			_viGear->_x = 600;
			_viGear->_y = 280;
			break;
		case Gear3:
			_viGear->_x = 750;
			_viGear->_y = 280;
			break;
		case Gear4:
			_viGear->_x = 900;
			_viGear->_y = 280;
			break;
		}
		if (KEYMANAGER->isToggleKey(VK_F1))
		{
			if (_viGear->_isGear == true)RectangleMake(getMemDC(), _viGear->_x + (_viGear->_rc.right - _viGear->_rc.left) / 2, _viGear->_y + (_viGear->_rc.bottom - _viGear->_rc.top) / 2,
				_viGear->_image->getWidth() / 2, _viGear->_image->getHeight() / 2);
		}
		if (_viGear->_isGear == true)_viGear->_image->render(getMemDC(), _viGear->_x, _viGear->_y);
	}
}

