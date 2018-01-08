#include "stdafx.h"
#include "NPCManager.h"


NPCManager::NPCManager()
{
}


NPCManager::~NPCManager()
{
}

HRESULT NPCManager::init()
{
	_CCount = 0;
	rc = RectMake(WINSIZEX / 2, 400, 50, 50);
	SOUNDMANAGER->addSound("TownBGM", "./Music/townBGM.mp3", true, true);
	SOUNDMANAGER->addSound("Stage", "./Music/StageBGM.mp3", true, true);
	SOUNDMANAGER->addSound("Rival", "./Music/First Battle.mp3", true, true);
	
	crrentMusicName = "TownBGM";
	oldMusicName = crrentMusicName;
	SOUNDMANAGER->play(crrentMusicName, 1.0f);
	_table = RectMake(2610, 510, 260, 20);				//테이블 렉트
	return S_OK;
}

void NPCManager::release()
{
}

void NPCManager::update()
{
	for (_viNPC = _vNPC.begin(); _viNPC != _vNPC.end(); )
	{
		(*_viNPC)->update();
		++_viNPC;
	}
	

	_p->update();
	//collision();
	player_npc_collision();
	
}

void NPCManager::render()
{
	for (_viNPC = _vNPC.begin(); _viNPC != _vNPC.end(); ++_viNPC)
	{
		(*_viNPC)->render();

	}
	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(rc.left), CAMERAMANAGER->CameraRelativePointY(rc.top), 50, 50);
	HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
	Rectangle(getMemDC(), _table.left, _table.top, _table.right, _table.bottom);
	FillRect(getMemDC(), &_table, brush);
	DeleteObject(brush);
	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_table.left), CAMERAMANAGER->CameraRelativePointY(_table.top), 260, 5);
	//TextOut(getMemDC(), 50, 350, str, strlen(str));
}

void NPCManager::setNpc()
{
	NPC* watergirl;
	watergirl = new waterGirl;
	watergirl->init("watergirl","watergirlColpix" ,PointMake(6400, 650), "./text/NPC/waterGirl.txt", "..", true, false, false, false);
	
	NPC* bard;
	bard = new Bard;
	bard->init("bardnomal","", PointMake(1865, 660), "./text/NPC/bard.txt", "./text/NPC/bard1-1.txt", false, false, true, false);

	NPC* molly;
	molly = new Molly;
	molly->init("몰리","" ,PointMake(2330, 650), "./text/NPC/몰리.txt", "..", false, false, false, false);

	NPC* gote;
	gote = new goatician;
	gote->init("염소", "", PointMake(3170, 650), "./text/NPC/goatician.txt","./text/NPC/goatician2.txt", false, false, true, true);

	NPC* _wizard;
	_wizard = new Wizard;
	_wizard->init("마법사", "", PointMake(3710, 365), "./text/NPC/위자드.txt", "./text/NPC/위자드1.txt", false, false, true, true);

	NPC* _cooker;
	_cooker = new Sepp;
	_cooker->init("요리사", "조리중", PointMake(2970,280), "./text/NPC/요리사.txt", "./text/NPC/요리사1.txt", false, false, true, false);

	NPC* _famer;
	_famer = new hedgeFarmer;
	_famer->init("hedgeFarmer", "" ,PointMake(5450, 650), "./text/NPC/마을사람.txt","...", false, false,false,false);

	NPC* _gard;
	_gard = new gard;
	_gard->init("guard", "", PointMake(300, 650), "./text/NPC/gard.txt", "./text/NPC/gard1.txt", false, false, true, false);

	NPC* _crown;
	_crown = new Crown;
	_crown->init("광대", "", PointMake(3470, 650), "./text/NPC/Merchant.txt", "./text/NPC/Merchant1.txt", false, false, true, true);
	
	_vNPC.push_back(watergirl);
	_vNPC.push_back(bard);			//음악시트
	_vNPC.push_back(molly);
	_vNPC.push_back(gote);			//음식티켓
	_vNPC.push_back(_wizard);		//마법사
	_vNPC.push_back(_cooker);
	_vNPC.push_back(_famer);
	_vNPC.push_back(_gard);
	_vNPC.push_back(_crown);		//유물

}

void NPCManager::setLeftNpc(bool _isRight)
{
	NPC* _bagFella;
	_bagFella = new bagFella;
	_bagFella->init("짐든 남자", "", PointMake(8200, 650), "./text/NPC/짐꾼.txt", "..", true, _isRight, false, false );

	_vNPC.push_back(_bagFella);

}

void NPCManager::setRightNpc(bool _isRight)
{
	NPC* _deerlady;
	_deerlady = new deerLady;
	_deerlady->init("deerLadyMove", "", PointMake(-10, 600), "./text/NPC/사슴여인.txt", "..", true, _isRight, false, false);

	_vNPC.push_back(_deerlady);
}


void NPCManager::removeNpc(int arrNum)
{
	SAFE_DELETE(_vNPC[arrNum]);
	_vNPC.erase(_vNPC.begin() + arrNum);
}

//void NPCManager::collision()
//{
//	
//	
//	RECT temp;
//
//	for (_viNPC = _vNPC.begin(); _viNPC != _vNPC.end();++_viNPC )
//	{
//		if (IntersectRect(&temp ,&(*_viNPC)->getimgRC(), &rc))
//		{
//			
//			if (!(*_viNPC)->getisTolk()) 
//			{
//				if (KEYMANAGER->isOnceKeyDown(VK_UP)) 
//				{
//					(*_viNPC)->setisTolk(true);
//					
//				}
//			}
//			if ((*_viNPC)->getisTolk()) {
//				_CCount++;
//				(*_viNPC)->Converstion(_CCount);
//			}
//			if (!(*_viNPC)->getisTolk()) {
//				_CCount = 0;
//				
//			}
//			if (KEYMANAGER->isOnceKeyDown('C'))
//			{
//				if ((*_viNPC)->getMusicStart()) {
//					SOUNDMANAGER->stop(oldMusicName);
//					crrentMusicName = (*_viNPC)->getMusicname();
//					SOUNDMANAGER->play(crrentMusicName, 1.0);
//					oldMusicName = crrentMusicName;
//				}
//			}
//			if (KEYMANAGER->isOnceKeyDown('X'))
//			{
//				(*_viNPC)->setcoversationCount(1);
//				if ((*_viNPC)->getcoversationCount() == 1) {
//					_CCount = 0;
//				}
//				if (!(*_viNPC)->getisSaller())
//				{
//					
//					if ((*_viNPC)->getisMusicSheet()) {
//						if ((*_viNPC)->getcoversationCount() >= 3) {
//							(*_viNPC)->setisTolk(false);
//							(*_viNPC)->setcoversationCount(-3);
//						}
//					}
//					else
//					{
//						if ((*_viNPC)->getcoversationCount() == 2) {
//							(*_viNPC)->setisTolk(false);
//							(*_viNPC)->setcoversationCount(-2);
//						}
//					}
//				}
//			
//			}
//			if (KEYMANAGER->isOnceKeyDown('Z'))
//			{
//				if (!(*_viNPC)->getisTiket())(*_viNPC)->setisgetTiket(true);
//				if(!(*_viNPC)->getisfirelod())(*_viNPC)->setisfirelod(true);
//				if (!(*_viNPC)->getisMusicSheet())(*_viNPC)->setisMusicSheet(true);
//			}
//			if (_CCount >= (*_viNPC)->gettxtSizeMax()) {
//				_CCount = (*_viNPC)->gettxtSizeMax();
//			}
//		
//		}
//		else
//		{
//			(*_viNPC)->setisTolk(false);
//			
//		}
//
//	}
//	if (IntersectRect(&temp, &_table, _p->getPlayerRect()))
//	{
//	//	isCollisionReaction(_table, _p->getPlayerRect());
//	}
//}

LPCOLLISION_INFO NPCManager::player_npc_collision()
{
	LPCOLLISION_INFO tempInfo = new COLLISION_INFO;
	RECT temp;
	for (int i =0 ; i< _vNPC.size();i++)
	{
		
		if (IntersectRect(&temp, &_vNPC[i]->getimgRC(), _p->getPlayerRect()))
		{
			//충돌메시지 작성
			tempInfo->_colType = COL_NPC;
			//tempInfo->index_detail = --- 세부번호
			if (!_vNPC[i]->getisTolk())
			{
				if (KEYMANAGER->isOnceKeyDown(VK_UP))
				{
					_vNPC[i]->setisTolk(true);
					
				}
			}
			if (_vNPC[i]->getisTolk()) {
				_CCount++;
				_vNPC[i]->Converstion(_CCount);
			}
			if (!_vNPC[i]->getisTolk()) {
				_CCount = 0;

			}
			//체스터 유물파는놈
			if (i == 10) {
				if (_vNPC[i]->getisBuyYes())
				{
					if (_vNPC[i]->getisfirelod())
					{
						_vNPC[6]->setisfirelod(true);
						_p->setEquipRelic(0);
					}
					if (_vNPC[i]->getisMusicSheet())
					{
						_vNPC[3]->setisMusicSheet(true);
						//악보 어떻게 넣냐?
					}
				}
			}
			// 유물이 있으면 
			else if (i == 6)
			{
				if (_p->getEquipRelic() == 0)
				{
					if (_vNPC[i]->getisBuyYes())
					{
							_p->setPlayerMaxMP(50);
						
					}
				}
			}
			//염소
			else if (i == 5)
			{
				if (_vNPC[i]->getisBuyYes())
				{
					_vNPC[7]->setisgetTiket(true);
				}
			}
			if (KEYMANAGER->isOnceKeyDown('C'))
			{
				if (_vNPC[i]->getMusicStart()) {
					SOUNDMANAGER->stop(oldMusicName);
					crrentMusicName = _vNPC[i]->getMusicname();
					SOUNDMANAGER->play(crrentMusicName, 1.0);
					oldMusicName = crrentMusicName;
				}
			}
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				_vNPC[i]->setcoversationCount(1);
				if (_vNPC[i]->getcoversationCount() == 1) {
					_CCount = 0;
				}
				if (!_vNPC[i]->getisSaller())
				{
					if (_vNPC[i]->getisMusicSheet()) {
						if (_vNPC[i]->getcoversationCount() >= 3) {
							_vNPC[i]->setisTolk(false);
							_vNPC[i]->setcoversationCount(-3);
						}
					}
					else
					{
						if (_vNPC[i]->getcoversationCount() == 2) {
							_vNPC[i]->setisTolk(false);
							_vNPC[i]->setcoversationCount(-2);
						}
					}
				}

			}
		/*	if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				if (!_vNPC[i]->getisTiket())(*_viNPC)->setisgetTiket(true);
				if (!_vNPC[i]->getisfirelod())(*_viNPC)->setisfirelod(true);
			}*/
			if (_CCount >= _vNPC[i]->gettxtSizeMax()) {
				_CCount = _vNPC[i]->gettxtSizeMax();
			}
		
		}
		else
		{
			_vNPC[i]->setisTolk(false);

		}
		sprintf_s(str, "is MAXMP:%d", _p->getPlayerMaxMP());
	}
	// 테이블 충돌시
	if (IntersectRect(&temp, &_table, _p->getPlayerRect())) 
	{
		//isCollisionReaction(_table, _p->getPlayerRect());
	}
	//충돌메시지 반환 -> 플레이어에 넘겨주면 플레이어가 _colType과 index_detail을 가지고 판단, 처리
	if (tempInfo->_colType != COL_NONE)
		return tempInfo;
	else return NULL;
}

