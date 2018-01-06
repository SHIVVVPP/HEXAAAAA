#include "stdafx.h"
#include "Wizard.h"


Wizard::Wizard()
{
}


Wizard::~Wizard()
{
}

void Wizard::tolkdrow()
{
	if (_istolk)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		Rectangle(getMemDC(), _tolkBox.left, _tolkBox.top, _tolkBox.right, _tolkBox.bottom);
		FillRect(getMemDC(), &_tolkBox, brush);
		DeleteObject(brush);
		SetTextColor(getMemDC(), RGB(255, 255, 255));

		if (!_isgetfirelod)
		{
			if (conversationCount == 0)
			{
				TXTDATA->NPCrender(fileName, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
			}
			else if (conversationCount >= 1)
			{
				TXTDATA->NPCrender(fileName2, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
			}
		}
		else 
		{
			if (conversationCount == 0)
			{
				TXTDATA->NPCrender("./text/NPC/위자드2.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
			}
			else if (conversationCount >= 1)
			{
				//식사권
				if (selectbox == selectNum0)
				{
					if (!_isSelect)
					{
						_tolkMaxsize = TXTDATA->textSize("./text/NPC/위자드3.txt", getMemDC());
						TXTDATA->render("./text/NPC/위자드3.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
					}
				}
				//던
				else if (selectbox == selectNum1)
				{
					if (!_isSelect)
					{
						_tolkMaxsize = TXTDATA->textSize("./text/NPC/Merchant3-1.txt", getMemDC());
						TXTDATA->render("./text/NPC/Merchant3-1.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
					}
				}
			}
		}
		if (_isSaller && conversationCount < 1)_conversaion->render(getMemDC());
		else if (_isSaller && conversationCount >= 1) 
		{
			if (!_isgetfirelod)
			{
				_conversaion->render(getMemDC());
			}
			else {
				_storeUI->render(getMemDC());
				_selectRectimg->render(getMemDC(), selectx, selecty);
				_posion->render(getMemDC(), 455, 160);
				_done->render(getMemDC(), 625, 190);
				if (_isSelect && selectbox == selectNum0)
				{
					_tolkMaxsize = TXTDATA->textSize("./text/NPC/Merchant3-0.txt", getMemDC());
					TXTDATA->render("./text/NPC/Merchant3-0.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
					_noBox->render(getMemDC(), 1100, 270);
					_yesBox->render(getMemDC(), 1400, 270);
					_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
				}
				else if (_isSelect && selectbox == selectNum1)
				{
					_tolkMaxsize = TXTDATA->textSize("./text/NPC/Merchant3-1.txt", getMemDC());
					TXTDATA->render("./text/NPC/Merchant3-1.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
					_noBox->render(getMemDC(), 1100, 270);
					_yesBox->render(getMemDC(), 1400, 270);
					_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
				}
			}
		}
	}
	TextOut(getMemDC(), 500, 500, str, strlen(str));
}

void Wizard::Converstion(int tolkCount)
{
	_tolkCout = tolkCount;
	sprintf_s(str, "_is :%d", _isgetfirelod);
	if (!_isSelect) {
		switch (selectbox)
		{
		case selectNum0:
		{
			selectx = 430;
			selecty = 140;
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) selectbox = selectNum1;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
		}
		break;
		case selectNum1:
		{
			selectx = 600;
			selecty = 140;
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) selectbox = selectNum0;
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
				_isBuyYes = true;
				_isSelect = false;
				_istolk = false;
				conversationCount = 0;

			}
			else
			{
				_isBuyYes = false;
				_isSelect = false;

			}
		}
	}


	if (conversationCount == 0)			//조절해야됨;
	{
		_tolkBox = RectMakeCenter(WINSIZEX / 2, 97, _conversaion->getWidth(), _conversaion->getHeight());
		_tolkboxX = 1600;																												//토크박스x
		_tolkboxY = 384;																												//토크박스y
		_tolkX = 235;																													//대화위치 x
		_tolkY = 50;																													//대화위치 y
		if(!_isgetfirelod)_tolkMaxsize = TXTDATA->textSize(fileName, getMemDC());																																//토크출력시간;
		else _tolkMaxsize = TXTDATA->textSize("./text/NPC/위자드2.txt", getMemDC());
	}
	else if (_isgetfirelod && conversationCount == 1)			//조절해야됨;
	{
		if (_isgetfirelod)
		{
			_tolkBox = RectMakeCenter(WINSIZEX / 2, 187, _storeUI->getWidth(), _storeUI->getHeight());
			_tolkboxX = 1540;																												//토크박스x
			_tolkboxY = 160;																												//토크박스y
			_tolkX = 500;																													//대화위치 x
			_tolkY = 50;																													//대화위치 y
			
			//토크출력시간;
		}
	}
	else if(!_isgetfirelod && conversationCount == 1)
	{
		_tolkBox = RectMakeCenter(WINSIZEX / 2, 97, _conversaion->getWidth(), _conversaion->getHeight());
		_tolkboxX = 1600;																												//토크박스x
		_tolkboxY = 384;																												//토크박스y
		_tolkX = 235;																													//대화위치 x
		_tolkY = 50;
	}

	if (conversationCount == 0) {
		selectbox = 0;
	}
}
