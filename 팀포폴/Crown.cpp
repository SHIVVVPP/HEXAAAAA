#include "stdafx.h"
#include "Crown.h"


Crown::Crown()
{
}


Crown::~Crown()
{
}

void Crown::Converstion(int tolkCount)
{
	_tolkCout = tolkCount;

	if (!_isSelect) {
		switch (selectbox)
		{
		case selectNum0:
		{
			selectx = 400;
			selecty = 60;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) selectbox = selectNum1;
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) selectbox = selectNum3;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
		}
		break;
		case selectNum1:
		{
			selectx = 550;
			selecty = 60;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) selectbox = selectNum0;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) selectbox = selectNum2;
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) selectbox = selectNum4;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
		}
		break;
		case selectNum2:
		{
			selectx = 700;
			selecty = 60;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) selectbox = selectNum1;
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) selectbox = selectNum5;

		}
		break;
		case selectNum3:
		{
			selectx = 400;
			selecty = 180;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) selectbox = selectNum4;
			if (KEYMANAGER->isOnceKeyDown(VK_UP)) selectbox = selectNum0;
		}
		break;
		case selectNum4:
		{
			selectx = 550;
			selecty = 180;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) selectbox = selectNum3;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) selectbox = selectNum5;
			if (KEYMANAGER->isOnceKeyDown(VK_UP)) selectbox = selectNum1;
		}
		break;
		case selectNum5:
		{
			selectx = 700;
			selecty = 180;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) selectbox = selectNum4;
			if (KEYMANAGER->isOnceKeyDown(VK_UP)) selectbox = selectNum2;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
		}
		break;

		}
	}
	else
	{

		if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) 
		{
			_selectBoxX = 1070;
			_selectBoxY = 260;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) 
		{
			_selectBoxX = 1390;
			_selectBoxY = 260;
		}

		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_isSelect = false;
		
		}
		if (KEYMANAGER->isOnceKeyDown('C')) 
		{
			if (_selectBoxX == 1390) {
				_isByYes = true;
				_isSelect = false;
				_istolk = false;
				conversationCount = 0;

			}
			else
			{
				_isByYes = false;
				_isSelect = false;
				_istolk = false;
				conversationCount = 0;
			}
		}
	}

}
