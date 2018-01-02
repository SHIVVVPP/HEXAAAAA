#include "stdafx.h"
#include "NPC.h"


NPC::NPC()
{
}


NPC::~NPC()
{

}

HRESULT NPC::init(const char * ImageName, POINT position, const char* _fileName, POINT Talkposition, POINT TalkBox, bool isRight)	//npc�� �̹��� �̸� , npc�� ��ġ,npc�� ��ȭ���� �̸�, ��ȭ ��ġ , ��ȭ �ڽ� , npc�� ������
{
	_Npcimage = IMAGEMANAGER->findImage(ImageName);																					//npc�� �̹����ҷ�����
	_imgrc = RectMake(position.x, position.y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());								//npc�� ��Ʈ ����

	_aniNpc = new animation;																										//�ִϸ��̼� ����
	_aniNpc->init(_Npcimage->getWidth(), _Npcimage->getHeight(), _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());			//�ִϸ��̼� �ʱ�ȭ
	_aniNpc->setDefPlayFrame(false, true);																							//
	_aniNpc->setFPS(1);																												//�ִϸ��̼� �ӵ�
	_aniNpc->start();
	_x = _imgrc.left + ((_imgrc.right - _imgrc.left) / 2);																			//npc�� �߽���ǥ x
	_y = _imgrc.top + ((_imgrc.bottom - _imgrc.top) / 2);																			//npc�� �߽���ǥ y
	_isRight = isRight;																												//�����ϴ� ��ǥ�� �������̳�
	fileName = _fileName;																											//���� �̸� ����
	_tolkboxX = TalkBox.x;																											//��ũ�ڽ�x
	_tolkboxY = TalkBox.y;																											//��ũ�ڽ�y
	_tolkX = Talkposition.x;																										//��ȭ��ġ x
	_tolkY = Talkposition.y;																										//��ȭ��ġ y
	_tolkCout = 0;																													//��ũ��½ð�;
	return S_OK;
}
void NPC::release()
{

}
void NPC::update()
{
	if (KEYMANAGER->isStayKeyDown('E'))_aniNpc->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

	Move(_isRight);
	
}
void NPC::render()
{
	if (KEYMANAGER->isToggleKey('F1')) {
		Rectangle(getMemDC(),_imgrc.left, _imgrc.top, _imgrc.right, _imgrc.bottom);

	}
	_Npcimage->aniRender(getMemDC(), _x, _y, _aniNpc);
}
void NPC::Move(bool isRight)
{
	if (isRight) {

	}
	else {

	}
}
void NPC::Converstion(int tolkCount)
{
	_tolkCout = tolkCount;
	TXTDATA->render(fileName, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, -1);
}