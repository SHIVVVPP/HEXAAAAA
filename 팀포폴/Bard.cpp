#include "stdafx.h"
#include "Bard.h"


Bard::Bard()
{
}


Bard::~Bard()
{
}

void Bard::tolkdrow()
{
	if (_istolk)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		Rectangle(getMemDC(), _tolkBox.left, _tolkBox.top, _tolkBox.right, _tolkBox.bottom);
		FillRect(getMemDC(), &_tolkBox, brush);
		DeleteObject(brush);
		SetTextColor(getMemDC(), RGB(255, 255, 255));

		if (!_isgetMusicSheet)
		{
			if (conversationCount == 0)
			{
				_tolkMaxsize = TXTDATA->textSize(fileName, getMemDC());
				TXTDATA->NPCrender(fileName, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
				_conversaion->render(getMemDC());
			}
			else if (conversationCount == 1)
			{
				_tolkMaxsize = TXTDATA->textSize(fileName2, getMemDC());
				TXTDATA->NPCrender(fileName2, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
				_conversaion->render(getMemDC());
			}
		}
		else
		{
			if (conversationCount == 0)
			{
				_tolkMaxsize = TXTDATA->textSize("./text/NPC/bard4.txt", getMemDC());
				TXTDATA->NPCrender("./text/NPC/bard4.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
			}
			else if (conversationCount == 1)
			{
				_tolkMaxsize = TXTDATA->textSize("./text/NPC/bard5.txt", getMemDC());
				TXTDATA->NPCrender("./text/NPC/bard5.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
			}
			
			
		}
		if (_isgetMusicSheet && conversationCount == 0) {
			_conversaion->render(getMemDC());
			_bardselectRectimg->render(getMemDC(), _selectBoxX, _selectBoxY);
			_bardYes->render(getMemDC(), 700, 140);
			_bardNo->render(getMemDC(), 1100, 140);
			
		}
		else if(_isgetMusicSheet && conversationCount == 1)_conversaion->render(getMemDC());
		else if (_isgetMusicSheet && conversationCount == 2)
		{
			if (!_isgetMusicSheet)
			{
				_conversaion->render(getMemDC());
			}
			else {
				_bardUI->render(getMemDC());
				_selectRectimg->render(getMemDC(), selectx, selecty);
				_bardUI2->render(getMemDC(), 200, 390);
				
				if (_isSelect)
				{
					if (selectbox == selectNum0)
					{
						_tolkMaxsize = TXTDATA->textSize("./text/NPC/bard6.txt", getMemDC());
						TXTDATA->render("./text/NPC/bard6.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
						_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
						_noBox->render(getMemDC(), 1100, 270);
						_yesBox->render(getMemDC(), 1400, 270);
					}
					else if (selectbox == selectNum1)
					{
						_tolkMaxsize = TXTDATA->textSize("./text/NPC/bard6.txt", getMemDC());
						TXTDATA->render("./text/NPC/bard6.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
						_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
						_noBox->render(getMemDC(), 1100, 270);
						_yesBox->render(getMemDC(), 1400, 270);
					}
					else if (selectbox == selectNum2)
					{
						_tolkMaxsize = TXTDATA->textSize("./text/NPC/bard6.txt", getMemDC());
						TXTDATA->render("./text/NPC/bard6.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
						_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
						_noBox->render(getMemDC(), 1100, 270);
						_yesBox->render(getMemDC(), 1400, 270);
					}
				}
				else 
				{
					if (selectbox == selectNum0)
					{
						_tolkMaxsize = TXTDATA->textSize("./text/NPC/튜토리얼.txt", getMemDC());
						TXTDATA->render("./text/NPC/튜토리얼.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
						_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
					}
					else if (selectbox == selectNum1)
					{
						_tolkMaxsize = TXTDATA->textSize("./text/NPC/라이벌.txt", getMemDC());
						TXTDATA->render("./text/NPC/라이벌.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
						_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
					}
					else if (selectbox == selectNum2)
					{
						_tolkMaxsize = TXTDATA->textSize("./text/NPC/마을.txt", getMemDC());
						TXTDATA->render("./text/NPC/마을.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
						_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
					}
					else {
						_tolkMaxsize = TXTDATA->textSize("./text/NPC/입수.txt", getMemDC());
						TXTDATA->render("./text/NPC/입수.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
						_selectBox->render(getMemDC(), _selectBoxX, _selectBoxY);
					}
				}
			}
		}
	}
}

void Bard::Converstion(int tolkCount)
{
	_tolkCout = tolkCount;
	if (!_isSelect) {
		switch (selectbox)
		{
		case selectNum0:
		{
			selectx = 380;
			selecty = 60;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) selectbox = selectNum1;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5)) selectbox = selectNum4;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
			MusicName = "Stage";
		}
		break;
		case selectNum1:
		{
			selectx = 495;
			selecty = 60;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) selectbox = selectNum0;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) selectbox = selectNum2;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5)) selectbox = selectNum5;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
			MusicName = "Rival";
		}
		break;
		case selectNum2:
		{
			selectx = 610;
			selecty = 60;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) selectbox = selectNum1;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) selectbox = selectNum3;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5)) selectbox = selectNum6;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
			MusicName = "TownBGM";
		}
		break;
		case selectNum3:
		{
			selectx = 720;
			selecty = 60;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) 	selectbox = selectNum2;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5)) selectbox = selectNum7;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;

		}
		break;
		case selectNum4:
		{
			selectx = 380;
			selecty = 230;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) selectbox = selectNum5;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8)) selectbox = selectNum0;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
		}
		break;
		case selectNum5:
		{
			selectx = 495;
			selecty = 230;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) selectbox = selectNum4;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) selectbox = selectNum6;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8)) selectbox = selectNum1;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;
		}
		break;
		case selectNum6:
		{
			selectx = 610;
			selecty = 230;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) selectbox = selectNum5;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) selectbox = selectNum7;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8)) selectbox = selectNum2;
			if (KEYMANAGER->isOnceKeyDown('C')) _isSelect = true;

		}
		break;
		case selectNum7:
		{
			selectx = 720;
			selecty = 230;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) selectbox = selectNum6;
			if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD8)) selectbox = selectNum3;
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
				_musicStart = true;
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
																																		//토크출력시간;
		//else _tolkMaxsize = TXTDATA->textSize("./text/NPC/위자드2.txt", getMemDC());
	}
	else if (_isgetMusicSheet && conversationCount == 1)
	{
		_tolkBox = RectMakeCenter(WINSIZEX / 2, 97, _conversaion->getWidth(), _conversaion->getHeight());
		_tolkboxX = 1600;																												//토크박스x
		_tolkboxY = 384;																												//토크박스y
		_tolkX = 235;																													//대화위치 x
		_tolkY = 50;																													//대화위치 y
																																	//토크출력시간;
		//else _tolkMaxsize = TXTDATA->textSize("./text/NPC/위자드2.txt", getMemDC());
	}
	else if (_isgetMusicSheet && conversationCount == 2)			//조절해야됨;
	{
		if (_isgetMusicSheet)
		{
			_tolkBox = RectMakeCenter(WINSIZEX / 2, 187, _storeUI->getWidth(), _storeUI->getHeight());
			_tolkboxX = 1540;																												//토크박스x
			_tolkboxY = 160;																												//토크박스y
			_tolkX = 500;																													//대화위치 x
			_tolkY = 50;																													//대화위치 y

																																			//토크출력시간;
		}
	}
	else if (!_isgetMusicSheet && conversationCount == 1)
	{
		_tolkBox = RectMakeCenter(WINSIZEX / 2, 97, _conversaion->getWidth(), _conversaion->getHeight());
		_tolkboxX = 1600;																												//토크박스x
		_tolkboxY = 384;																												//토크박스y
		_tolkX = 235;																													//대화위치 x
		_tolkY = 50;
	}
	else if (!_isgetMusicSheet && conversationCount >= 2)
	{
		conversationCount = 0;
		_istolk = false;
	}
	if (conversationCount == 0) {
		selectbox = 0;
	}
}
