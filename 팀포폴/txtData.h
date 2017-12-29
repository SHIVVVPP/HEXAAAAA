#pragma once
#include "singletonBase.h"
#include <vector>
#include <string>

class txtData : public singletonBase<txtData>
{
private:

public:
	HRESULT init();
	void release();
	
	//Save
	void txtSave(const char* saveFileName, vector<string> vStr);
	char* vectorArrayCombine(vector<string> vArray);
	
	//Load
	vector<string> txtLoad(const char* loadFileName);
	vector<string> charArraySeparation(char charArray[]);
	void render(const char* loadFileName,HDC hdc, int x, int y, float width, float height, int outputNum);

	txtData();
	~txtData();
};

