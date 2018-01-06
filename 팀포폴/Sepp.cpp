#include "stdafx.h"
#include "Sepp.h"


Sepp::Sepp()
{
}


Sepp::~Sepp()
{
}

void Sepp::aniMove()
{
	if (!_isgetTiket)
	{
		_aniNpc->setDefPlayFrame(false, true);																							//
	}
	else if (_isgetTiket)
	{
		_Npcimage = IMAGEMANAGER->findImage("조리중");
		_aniNpc->setDefPlayFrame(false, true);
	}
	
}

void Sepp::tolkdrow()
{
	if (_istolk)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		Rectangle(getMemDC(), _tolkBox.left, _tolkBox.top, _tolkBox.right, _tolkBox.bottom);
		FillRect(getMemDC(), &_tolkBox, brush);
		DeleteObject(brush);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		if (_isMoreConverstion && !_isSaller && !_isgetTiket)
		{
			if (conversationCount == 0) {
				TXTDATA->NPCrender(fileName, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
				_conversaion->render(getMemDC());
			}
			else if (conversationCount == 1)
			{
				_tolkMaxsize = TXTDATA->textSize(fileName2, getMemDC());
				TXTDATA->NPCrender(fileName2, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
				_conversaion->render(getMemDC());
			}
			else if (conversationCount == 2)
			{
				_istolk = false;
			}
		}
		else if (_isMoreConverstion && !_isSaller && _isgetTiket)
		{
			
				_tolkMaxsize = TXTDATA->textSize("./text/NPC/요리사2.txt", getMemDC());
				TXTDATA->NPCrender("./text/NPC/요리사2.txt", getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
				_conversaion->render(getMemDC());
				
			
		}
	}
}

void Sepp::Converstion(int tolkCount)
{
	
		_tolkCout = tolkCount;
		if (_tolkCout != 0) {
			_istolk = true;
		}
		if (!_istolk) {
			conversationCount = 0;
		}
	
}
