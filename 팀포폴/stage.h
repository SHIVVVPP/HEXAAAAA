#pragma once
#include "gameNode.h"
#include "settingTool.h"
#include <map>

class objectManager;
class player;
class ui;

struct tagRoomInfo
{
	string myKey;
	int _index;
	int _leftX, _topY;
	int _width, _height;
	image* _roomImage;
	image* _pixelColImage;
	vector<string> _vConnectedRoom;	
};

class stage : public gameNode
{
private:
	typedef map<string, tagRoomInfo> mRoom;
	typedef map<string, tagRoomInfo>::iterator miRoom;

private:
	mRoom _mRoom;
	tagRoomInfo _currentRoom;
	tagRoomInfo _prevRoom;

	int _currentRoomNum;
	player* _player;
	ui* _ui;
	objectManager* _objectManager;

	//�ӽ� ��Ʈ

	RECT _rc;

	settingTool* Tool;

public:
	stage();
	~stage();

	HRESULT init();
	void release();
	void update();
	void render();

	void setStageBackgroundInfo();
	tagRoomInfo findRoomInfo(string key);

	void setCameraObject();

	void  AddressLinkWithPlayer(player* _p) { _player = _p; }


	void sendColMessage();
	void pixelCollison();
};
