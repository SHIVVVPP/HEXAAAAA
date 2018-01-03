 #pragma once
#include "gameNode.h"
#include <map>


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
	typedef map<string, tagRoomInfo> miRoom;

private:
	mRoom _mRoom;
	tagRoomInfo _currentRoom;
	tagRoomInfo _prevRoom;

	int _currentRoomNum;
	

public:
	stage();
	~stage();

	HRESULT init();
	void release();
	void update();
	void render();

	void setStageBackgroundInfo();

};

