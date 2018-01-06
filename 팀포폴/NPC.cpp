#include "stdafx.h"
#include "NPC.h"


NPC::NPC()
{
}


NPC::~NPC()
{

}

HRESULT NPC::init(const char * ImageName, const char * ImageName2, POINT position, const char* _fileName, const char* _fileName2, bool isMove, bool isRight, bool ismoreConversation, bool isSaller)
{
	_Npcimage = IMAGEMANAGER->findImage(ImageName);																					//npc의 이미지불러오기
	_imgrc = RectMake(position.x, position.y, _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());								//npc의 렉트 생성
	_imgName = ImageName;
	_imgName2 = ImageName2;
	_aniNpc = new animation;																										//애니메이션 선언
	_aniNpc->init(_Npcimage->getWidth(), _Npcimage->getHeight(), _Npcimage->getFrameWidth(), _Npcimage->getFrameHeight());			//애니메이션 초기화

	_conversaion = IMAGEMANAGER->findImage("conversationRect");
	_tolkBox = RectMakeCenter(WINSIZEX/2, 97, _conversaion->getWidth(), _conversaion->getHeight());

	_storeUI = IMAGEMANAGER->findImage("상점");

	_firelod = IMAGEMANAGER->findImage("firelod");
	_invenMusicSheet = IMAGEMANAGER->findImage("invenMusicSheet");
	_invenMealTickets = IMAGEMANAGER->findImage("invenMealTickets");
	_posion = IMAGEMANAGER->findImage("포션");
	_selectRectimg = IMAGEMANAGER->findImage("선택박스");
	_done = IMAGEMANAGER->findImage("안삼");

	_yesBox = IMAGEMANAGER->findImage("선택안된YES");
	_noBox = IMAGEMANAGER->findImage("선택안된NO");
	_selectBox = IMAGEMANAGER->findImage("선택BOX");

	_x = _imgrc.left + ((_imgrc.right - _imgrc.left) / 2);																			//npc의 중심좌표 x
	_y = _imgrc.top + ((_imgrc.bottom - _imgrc.top) / 2);																			//npc의 중심좌표 y
																
	_LeftStartMoveX = -5;																											//MOVEnpc 왼쪽 시작지점
	_RightStartMoveX = 4210;																										//MOVEnpc 오른쪽 시작지점

	NpcSpeed = 5;																													//NPC의 이동속도

	_isMove = isMove;																												//움직이는 npc니?
	_isRight = isRight;																												//시작하는 좌표가 오른쪽이냐
	_isMoreConverstion = ismoreConversation;																					    //대화가 더있니?
	_isSaller = isSaller;																										    //NPC가 판매자니
	fileName = _fileName;																											//파일 이름 저장
	fileName2 = _fileName2;																											//파일 이름 저장
	_tolkMaxsize = TXTDATA->textSize(fileName, getMemDC());
	_tolkboxX = 1540;																												//토크박스x
	_tolkboxY = 160;																												//토크박스y
	_tolkX = 235;																													//대화위치 x
	_tolkY = 50;																													//대화위치 y
	_tolkCout = 0;																													//토크출력시간;
	selectbox = 0;
	selectx = 400;
	selecty = 60;
	crrentx = crrenty  = conversationCount = 0;
	_isSelect = _istolk = false;																									//토크 출력 컨트롤 불값
	_isBuyYes = false;																												//처음은 NO;
	_isgetTiket = _isgetfirelod = false;
	aniMove();
	_aniNpc->setFPS(1);																												//애니메이션 속도
	_aniNpc->start();

	
	return S_OK;
}
void NPC::release()
{

}
void NPC::update()
{
	
	_aniNpc->frameUpdate(TIMEMANAGER->getElapsedTime() * 4);
	//Move(_isMove,_isRight);
	
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
			if (conversationCount == 0)
			{
				TXTDATA->NPCrender(fileName, getMemDC(), _tolkX, _tolkY, _tolkboxX, _tolkboxY, _tolkCout, 40);
				_conversaion->render(getMemDC());
			}
			else {
				conversationCount = 0;
					_istolk = false;
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
	if (_isMvoe)																												//움직이는 NPC
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