#include "stdafx.h"
#include "Crown.h"


Crown::Crown()
{
}


Crown::~Crown()
{
}

void Crown::tolkdrow()
{
	if (_istolk)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		Rectangle(getMemDC(), _tolkBox.left, _tolkBox.top, _tolkBox.right, _tolkBox.bottom);
		FillRect(getMemDC(), &_tolkBox, brush);
		DeleteObject(brush);
		SetTextColor(getMemDC(), RGB(255, 255, 255));

		if (_isMoreConverstion && _isSaller) {
			if (conversationCount == 0)
			{
				TXTDATA->NPCrender(fileName, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
			}
			else if (conversationCount >= 1)
			{

				if (selectbox == selectNum0)
				{
					if (!_isSelect)
					{
						_tolkMaxsize = TXTDATA->textSize(fileName2, getMemDC());
						TXTDATA->render(fileName2, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
					}
				}
				else if (selectbox == selectNum1)
				{
					if (!_isSelect)
					{
						_tolkMaxsize = TXTDATA->textSize("./text/NPC/Merchant2.txt", getMemDC());
						TXTDATA->render("./text/NPC/Merchant2.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
					}
				}
				else if (selectbox == selectNum5)
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
		else if (_isSaller && conversationCount >= 1) {
			_storeUI->render(getMemDC());
			_selectRectimg->render(getMemDC(), selectx, selecty);
			_firelod->render(getMemDC(), 400, 50);
			_invenMusicSheet->render(getMemDC(), 550, 50);
			_done->render(getMemDC(), 725, 230);
			if (_isSelect&& selectbox == selectNum0)
			{
				_tolkMaxsize = TXTDATA->textSize("./text/NPC/Merchant3-0.txt", getMemDC());
				TXTDATA->render("./text/NPC/Merchant3-0.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
				_noBox->render(getMemDC(), 1100, 270);
				_yesBox->render(getMemDC(), 1400, 270);
				_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
				_isgetfirelod = true;
			}
			else if (_isSelect&& selectbox == selectNum1)
			{
				_tolkMaxsize = TXTDATA->textSize("./text/NPC/Merchant3-0.txt", getMemDC());
				TXTDATA->render("./text/NPC/Merchant3-0.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
				_noBox->render(getMemDC(), 1100, 270);
				_yesBox->render(getMemDC(), 1400, 270);
				_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
				_isgetMusicSheet = true;
			}
			else if (_isSelect && selectbox == selectNum5)
			{
				_tolkMaxsize = TXTDATA->textSize("./text/NPC/Merchant3-1.txt", getMemDC());
				TXTDATA->render("./text/NPC/Merchant3-1.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
				_noBox->render(getMemDC(), 1100, 270);
				_yesBox->render(getMemDC(), 1400, 270);
				_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
			}
		}
	}
	//TextOut(getMemDC(), 50, 350, str, strlen(str));
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
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) selectbox = selectNum1;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5)) selectbox = selectNum3;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
			_isgetfirelod = false;
		}
		break;
		case selectNum1:
		{
			selectx = 550;
			selecty = 60;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) selectbox = selectNum0;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) selectbox = selectNum2;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5)) selectbox = selectNum4;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
			_isgetMusicSheet = false;
		}
		break;
		case selectNum2:
		{
			selectx = 700;
			selecty = 60;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) selectbox = selectNum1;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5)) selectbox = selectNum5;

		}
		break;
		case selectNum3:
		{
			selectx = 400;
			selecty = 180;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) selectbox = selectNum4;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8)) 	selectbox = selectNum0;
				
		
		}
		break;
		case selectNum4:
		{
			selectx = 550;
			selecty = 180;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) selectbox = selectNum3;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) selectbox = selectNum5;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8)) 	sprintf(str, "selectbox : %d", selectbox);
			
		}
		break;
		case selectNum5:
		{
			selectx = 700;
			selecty = 180;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) selectbox = selectNum4;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8) && !_isSelect) selectbox = selectNum2;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
		}
		break;

		}
	}
	else
	{

		if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4))
		{
			_selectBoxX = 1070;
			_selectBoxY = 260;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6))
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
	if (_isSaller && conversationCount == 0)			//�����ؾߵ�;
	{
		_tolkBox = RectMakeCenter(WINSIZEX / 2, 97, _conversaion->getWidth(), _conversaion->getHeight());
		_tolkboxX = 1600;																												//��ũ�ڽ�x
		_tolkboxY = 384;																												//��ũ�ڽ�y
		_tolkX = 235;																													//��ȭ��ġ x
		_tolkY = 50;																													//��ȭ��ġ y
		_tolkMaxsize = TXTDATA->textSize(fileName, getMemDC());																																//��ũ��½ð�;
	}
	else if (_isSaller && conversationCount == 1)			//�����ؾߵ�;
	{
		_tolkBox = RectMakeCenter(WINSIZEX / 2, 187, _storeUI->getWidth(), _storeUI->getHeight());
		_tolkboxX = 1540;																												//��ũ�ڽ�x
		_tolkboxY = 160;																												//��ũ�ڽ�y
		_tolkX = 500;																													//��ȭ��ġ x
		_tolkY = 50;																													//��ȭ��ġ y
		_tolkCout = _tolkMaxsize;																										//��ũ��½ð�;
	}

	if (conversationCount == 0) {
		selectbox = 0;
	}
}
