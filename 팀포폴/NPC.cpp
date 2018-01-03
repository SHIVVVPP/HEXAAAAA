#include "stdafx.h"
#include "NPC.h"


NPC::NPC()
{
}


NPC::~NPC()
{

}

HRESULT NPC::init(const char * ImageName, POINT position, const char* _fileName, bool isMove ,bool isRight)	//npc�� �̹��� �̸� , npc�� ��ġ,npc�� ��ȭ���� �̸�, ��ȭ ��ġ , ��ȭ �ڽ� , npc�� ������
{
	_Npcimage = IMAGEMANAGER->findImage(ImageName);																					//npc�� �̹����ҷ�����
	_imgrc = RectMake(position.x, position.y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());								//npc�� ��Ʈ ����

	_aniNpc = new animation;																										//�ִϸ��̼� ����
	_aniNpc->init(_Npcimage->getWidth(), _Npcimage->getHeight(), _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());			//�ִϸ��̼� �ʱ�ȭ

	_conversaion = IMAGEMANAGER->findImage("conversationRect");
	_tolkBox = RectMakeCenter(WINSIZEX/2, 97, _conversaion->getWidth(), _conversaion->getHeight());

	if (!isMove) {
		_aniNpc->setDefPlayFrame(false, true);																							//
	}
	else {
		if (isRight) 
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
	_aniNpc->setFPS(1);																												//�ִϸ��̼� �ӵ�
	_aniNpc->start();

	_x = _imgrc.left + ((_imgrc.right - _imgrc.left) / 2);																			//npc�� �߽���ǥ x
	_y = _imgrc.top + ((_imgrc.bottom - _imgrc.top) / 2);																			//npc�� �߽���ǥ y
																
	_LeftStartMoveX = -5;																											//MOVEnpc ���� ��������
	_RightStartMoveX = 4210;																										//MOVEnpc ������ ��������

	NpcSpeed = 5;																													//NPC�� �̵��ӵ�

	_isMove = isMove;																												//�����̴� npc��?
	_isRight = isRight;																												//�����ϴ� ��ǥ�� �������̳�
	fileName = _fileName;																											//���� �̸� ����
	_tolkboxX = 1540;																											//��ũ�ڽ�x
	_tolkboxY = 160;																											//��ũ�ڽ�y
	_tolkX = 235;																										//��ȭ��ġ x
	_tolkY = 50;																										//��ȭ��ġ y
	_tolkCout = 0;																													//��ũ��½ð�;
	
	_istolk = false;																												//��ũ ��� ��Ʈ�� �Ұ�

	return S_OK;
}
void NPC::release()
{

}
void NPC::update()
{
	_aniNpc->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);

	Move(_isMove,_isRight);
	
}
void NPC::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1)) {
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());

	}
//	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());
	_Npcimage->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePoint(_imgrc).x, CAMERAMANAGER->CameraRelativePoint(_imgrc).y, _aniNpc);
	
	
	if (_istolk) 
	{	
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		Rectangle(getMemDC(), _tolkBox.left, _tolkBox.top, _tolkBox.right, _tolkBox.bottom);
		FillRect(getMemDC(), &_tolkBox, brush);
		DeleteObject(brush);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TXTDATA->render(fileName, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
		_conversaion->render(getMemDC());
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
		//RectMake(_x, _y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());
	}
}
void NPC::Converstion(int tolkCount)
{
	_tolkCout = tolkCount;
	_istolk = true;
	
}