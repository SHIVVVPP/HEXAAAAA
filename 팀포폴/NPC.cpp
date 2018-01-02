#include "stdafx.h"
#include "NPC.h"


NPC::NPC()
{
}


NPC::~NPC()
{

}

HRESULT NPC::init(const char * ImageName, POINT position, const char* _fileName, POINT Talkposition, POINT TalkBox, bool isRight)	//npc의 이미지 이름 , npc의 위치,npc의 대화파일 이름, 대화 위치 , 대화 박스 , npc의 움직임
{
	_Npcimage = IMAGEMANAGER->findImage(ImageName);																					//npc의 이미지불러오기
	_imgrc = RectMake(position.x, position.y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());								//npc의 렉트 생성

	_aniNpc = new animation;																										//애니메이션 선언
	_aniNpc->init(_Npcimage->getWidth(), _Npcimage->getHeight(), _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());			//애니메이션 초기화
	_aniNpc->setDefPlayFrame(false, true);																							//
	_aniNpc->setFPS(1);																												//애니메이션 속도
	_aniNpc->start();
	_x = _imgrc.left + ((_imgrc.right - _imgrc.left) / 2);																			//npc의 중심좌표 x
	_y = _imgrc.top + ((_imgrc.bottom - _imgrc.top) / 2);																			//npc의 중심좌표 y
	_isRight = isRight;																												//시작하는 좌표가 오른쪽이냐
	fileName = _fileName;																											//파일 이름 저장
	_tolkboxX = TalkBox.x;																											//토크박스x
	_tolkboxY = TalkBox.y;																											//토크박스y
	_tolkX = Talkposition.x;																										//대화위치 x
	_tolkY = Talkposition.y;																										//대화위치 y
	_tolkCout = 0;																													//토크출력시간;
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