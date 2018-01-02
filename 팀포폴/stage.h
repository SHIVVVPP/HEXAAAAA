#pragma once
#include "gameNode.h"
#include <map>
#include <vector>

class stage : public gameNode
{
private:

private:
	int _currentRoomNum;
	vector<int> _vCunnectedRoomNum;

public:
	stage();
	~stage();

	HRESULT init();
	void release();
	void update();
	void render();

	void stageBackgroundSet(int roomNumber);

};

