#include "stdafx.h"
#include "NPC.h"


NPC::NPC()
{
}


NPC::~NPC()
{

}

HRESULT NPC::init(const char * ImageName, POINT position, const char* _fileName, const char* _fileName2, bool isMove, bool isRight, bool ismoreConversation, bool isSaller)
{
	_Npcimage = IMAGEMANAGER->findImage(ImageName);																					//npc�� �̹����ҷ�����
	_imgrc = RectMake(position.x, position.y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());								//npc�� ��Ʈ ����

	_aniNpc = new animation;																										//�ִϸ��̼� ����
	_aniNpc->init(_Npcimage->getWidth(), _Npcimage->getHeight(), _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());			//�ִϸ��̼� �ʱ�ȭ

	_conversaion = IMAGEMANAGER->findImage("conversationRect");
	_tolkBox = RectMakeCenter(WINSIZEX/2, 97, _conversaion->getWidth(), _conversaion->getHeight());

	_storeUI = IMAGEMANAGER->findImage("����");

	_firelod = IMAGEMANAGER->findImage("firelod");
	_invenMusicSheet = IMAGEMANAGER->findImage("invenMusicSheet");
	_invenMealTickets = IMAGEMANAGER->findImage("invenMealTickets");
	_selectRectimg = IMAGEMANAGER->findImage("���ùڽ�");
	_done = IMAGEMANAGER->findImage("�Ȼ�");

	_yesBox = IMAGEMANAGER->findImage("���þȵ�YES");
	_noBox = IMAGEMANAGER->findImage("���þȵ�NO");
	_selectBox = IMAGEMANAGER->findImage("����BOX");

	_x = _imgrc.left + ((_imgrc.right - _imgrc.left) / 2);																			//npc�� �߽���ǥ x
	_y = _imgrc.top + ((_imgrc.bottom - _imgrc.top) / 2);																			//npc�� �߽���ǥ y
																
	_LeftStartMoveX = -5;																											//MOVEnpc ���� ��������
	_RightStartMoveX = 4210;																										//MOVEnpc ������ ��������

	NpcSpeed = 5;																													//NPC�� �̵��ӵ�

	_isMove = isMove;																												//�����̴� npc��?
	_isRight = isRight;																												//�����ϴ� ��ǥ�� �������̳�
	_isMoreConverstion = ismoreConversation;																					    //��ȭ�� ���ִ�?
	_isSaller = isSaller;																										    //NPC�� �Ǹ��ڴ�
	fileName = _fileName;																											//���� �̸� ����
	fileName2 = _fileName2;																											//���� �̸� ����
	_tolkMaxsize = TXTDATA->textSize(fileName, getMemDC());
	_tolkboxX = 1540;																												//��ũ�ڽ�x
	_tolkboxY = 160;																												//��ũ�ڽ�y
	_tolkX = 235;																													//��ȭ��ġ x
	_tolkY = 50;																													//��ȭ��ġ y
	_tolkCout = 0;																													//��ũ��½ð�;
	selectbox = 0;
	selectx = 400;
	selecty = 60;
	conversationCount = 0;
	_isSelect = _istolk = false;																									//��ũ ��� ��Ʈ�� �Ұ�
	_isBuyYes = false;																												//ó���� NO;
	_isgetTiket = _isgetfirelod = true;
	aniMove();
	_aniNpc->setFPS(1);																												//�ִϸ��̼� �ӵ�
	_aniNpc->start();

	
	return S_OK;
}
void NPC::release()
{

}
void NPC::update()
{
	//aniMove();
	_aniNpc->frameUpdate(TIMEMANAGER->getElapsedTime() * 4);
	//Move(_isMove,_isRight);

	if (_isSaller && conversationCount == 1)			//�����ؾߵ�;
	{
		_tolkBox = RectMakeCenter(WINSIZEX / 2, 187, _storeUI->getWidth(), _storeUI->getHeight());
		_tolkboxX = 1540;																												//��ũ�ڽ�x
		_tolkboxY = 160;																												//��ũ�ڽ�y
		_tolkX = 500;																													//��ȭ��ġ x
		_tolkY = 50;																													//��ȭ��ġ y
		_tolkCout = _tolkMaxsize;																										//��ũ��½ð�;
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

	if (conversationCount == 0) {
		selectbox = 0;
	}
	
}
void NPC::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1)) {
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());

	}
//	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());
	_Npcimage->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y, _aniNpc);
	
	tolkdrow();
	
	
}
void NPC::aniMove()
{
	if (!_isMove) {
		_aniNpc->setDefPlayFrame(false, true);																							//
	}
	else {
		if (_isRight)
		{
			int arrAni[] = { 0, 1 };
			_aniNpc->setPlayFrame(arrAni, 0, true);
		}
		else
		{
			int arrAni[] = { 3, 2 };
			_aniNpc->setPlayFrame(arrAni, 2, true);
		}
	}
}
void NPC::tolkdrow()
{
	if (_istolk)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		Rectangle(getMemDC(), _tolkBox.left, _tolkBox.top, _tolkBox.right, _tolkBox.bottom);
		FillRect(getMemDC(), &_tolkBox, brush);
		DeleteObject(brush);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		if (!_isMoreConverstion && !_isSaller)
		{
			TXTDATA->NPCrender(fileName, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
			if (KEYMANAGER->isOnceKeyDown('X')) {
				if (_tolkCout == _tolkMaxsize)
				{
					_istolk = false;
				}
			}
			
		}

		else if (_isMoreConverstion && !_isSaller)
		{
			if (conversationCount == 0) {
				TXTDATA->NPCrender(fileName, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
				_conversaion->render(getMemDC());
			}
			else if(conversationCount == 1)
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
	}
}
void NPC::Move(bool _isMvoe, bool _isRight)
{
	if (_isMvoe)																												//�����̴� NPC
	{
		if (_isRight)
		{
			_x = _RightStartMoveX;
			_x += NpcSpeed;
		}
		else
		{
			_x = _LeftStartMoveX;
			_x += NpcSpeed;
		}
	
	}
}
void NPC::Converstion(int tolkCount)
{
	_tolkCout = tolkCount;
	if (_tolkCout != 0) {
		_istolk = true;
	}
	if (!_istolk) {
		conversationCount = 0;
	}
}