#pragma once
#include "gameNode.h"
#include <map>

class player;


struct tagRoomInfo
{
	int _index;
	int _leftX, _topY;
	int _width, _height;
	image* _roomImage;
	image* _pixelColImage;
	
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

	//�ӽ� ��Ʈ

	RECT _rc;


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

	void pixelCollison();
};
