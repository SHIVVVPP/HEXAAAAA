#include "stdafx.h"
#include "settingTool.h"


settingTool::settingTool()
{
}


settingTool::~settingTool()
{
}


HRESULT settingTool::init()
{
	_rc = RectMakeCenter(0, 0, 0, 0);
	_image = NULL;
	TYPE = OBJECT;
	detail = 0;

	return S_OK;
}
void settingTool::release()
{
}
void settingTool::update()
{
	
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8))
	{
		switch (TYPE)
		{
		case OBJECT:
			if (detail == 8) detail = 0;
			else detail++;
			break;
		case MONSTER:
			if (detail == 4) detail = 0;
			else detail++;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD2))
	{
		switch (TYPE)
		{
		case OBJECT:
			if (detail == 0) detail = 8;
			else detail--;
			break;
		case MONSTER:
			if (detail == 0) detail = 4;
			else detail--;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5))
	{
		switch (TYPE)
		{
		case OBJECT:
			TYPE = MONSTER;
			detail = 0;
			break;
		case MONSTER:
			TYPE = OBJECT;
			detail = 0;
			break;
		}
	}

	switch (TYPE)
	{

		/*
		OBJECT
		fakehead_left 0
		fakehead_right 1
		fakeline_left 2
		fakeline_right 3
		faketail_left 4
		faketail_right 5
		goldplatter 6
		platter 7
		moving_block 8*/

	case OBJECT:
		switch (detail)
		{
		case 0:
			_image = IMAGEMANAGER->findImage("leftfakehead");
			break;
		case 1:
			_image = IMAGEMANAGER->findImage("rightfakehead");
			break;
		case 2:
			_image = IMAGEMANAGER->findImage("leftfakehead");
			break;
		case 3:
			_image = IMAGEMANAGER->findImage("leftfakeline");
			break;
		case 4:
			_image = IMAGEMANAGER->findImage("rightfakeline");
			break;
		case 5:
			_image = IMAGEMANAGER->findImage("leftfaketail");
			break;
		case 6:
			_image = IMAGEMANAGER->findImage("rightfaketail");
			break;
		case 7:
			_image = IMAGEMANAGER->findImage("platter");
			break;
		case 8:
			_image = IMAGEMANAGER->findImage("platter");
			break;
		}
		break;



		/*  
		MONSTER
			노란드래곤 0
			레드비틀 1
			스켈레톤 2
			슬라임 3
			초록용 4
			*/
	case MONSTER:
		switch (detail)
		{
		case 0:
			_image = IMAGEMANAGER->findImage("노란용");
			break;
		case 1:
			_image = IMAGEMANAGER->findImage("레드비틀");
			break;
		case 2:
			_image = IMAGEMANAGER->findImage("보스");
			break;
		case 3:
			_image = IMAGEMANAGER->findImage("슬라임");
			break;
		case 4:
			_image = IMAGEMANAGER->findImage("초록용");
			break;
		}
		break;
	}

	switch (TYPE)
	{
	case OBJECT:
		_rc = RectMakeCenter(_ptMouse.x, _ptMouse.y, _image->getWidth(), _image->getHeight());
		break;
	case MONSTER:
		_rc = RectMakeCenter(_ptMouse.x, _ptMouse.y, _image->getFrameWidth(), _image->getFrameHeight());
		break;
	}
}
void settingTool::render()
{
	switch (TYPE)
	{
	case OBJECT:
		_image->render(getMemDC(), _rc.left, _rc.top);
		break;
	case MONSTER:
		_image->frameRender(getMemDC(), _rc.left, _rc.top, 0, 0);
		break;
	}

	char str[128];
	sprintf(str, "leftX %d, topY %d", _rc.left + CAMERAMANAGER->getCameraPoint().x, _rc.top + CAMERAMANAGER->getCameraPoint().y);
	TextOut(getMemDC(), _rc.left, _rc.top - 20, str, strlen(str));
}