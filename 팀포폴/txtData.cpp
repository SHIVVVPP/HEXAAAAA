#include "stdafx.h"
#include "txtData.h"


txtData::txtData()
{
}


txtData::~txtData()
{

}

HRESULT txtData::init()
{
	return S_OK;
}

void txtData::release()
{

}


//Save
void txtData::txtSave(const char* saveFileName, vector<string> vStr)
{
	HANDLE file;

	DWORD write;
	char str[1025];
	strncpy_s(str, 128, vectorArrayCombine(vStr), 126);

	file = CreateFile(saveFileName, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 128, &write, NULL);

	CloseHandle(file);
	
}

char* txtData::vectorArrayCombine(vector<string> vArray)
{
	
	char str[1025];
	ZeroMemory(str, sizeof(str));
	
	for ( int i = 0; i < vArray.size(); i++ )
	{
		strncat_s(str, 128, vArray[i].c_str(), 126);
		
		if ( i + 1 < vArray.size() ) strcat(str, ",");
	}

	return str;
}




//Load
vector<string> txtData::txtLoad(const char* loadFileName)
{
	HANDLE file;
	char str[1025];
	
	DWORD read;

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 1025, &read, NULL);

	CloseHandle(file);

	return charArraySeparation(str);
}

vector<string> txtData::charArraySeparation(char charArray[])
{
	vector<string> vArray;
	char str[1025];
	char* temp;
	char* separator = ",";
	char* token;

	token = strtok(charArray, separator);
	vArray.push_back(token);

	while ( NULL != (token = strtok(NULL, separator)) )
	{
		vArray.push_back(token);
	}

	return vArray;
}

void txtData::render(const char* loadFileName,HDC hdc, int x, int y, float width, float height, int outputNum , int fontSize)
{
	HANDLE file;

	DWORD read;

	char str[1025];

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 1025, &read, NULL);

	CloseHandle(file);

	SetBkMode(hdc, TRANSPARENT);

	HFONT font, oldFont;

	font = CreateFont(fontSize, 0, 0, 0, 600, 0, 0, 0, DEFAULT_CHARSET,
		OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("./text/PressStart2P.ttf"));
	oldFont = (HFONT)SelectObject(hdc, font);

	DeleteObject(font);
	DeleteObject(oldFont);
	RECT _rc = RectMake(x, y, width, height); //넣을좌표

	DrawText(hdc, str, outputNum, &_rc, DT_CENTER | DT_WORDBREAK); //출력위치.
}

void txtData::NPCrender(const char * loadFileName, HDC hdc, int x, int y, float width, float height, int outputNum, int fontSize)
{
	HANDLE file;

	DWORD read;

	char str[1025];

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 1025, &read, NULL);

	CloseHandle(file);

	SetBkMode(hdc, TRANSPARENT);

	HFONT font, oldFont;

	font = CreateFont(fontSize, 0, 0, 0, 600, 0, 0, 0, DEFAULT_CHARSET,
		OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("./text/PressStart2P.ttf"));
	oldFont = (HFONT)SelectObject(hdc, font);

	DeleteObject(font);
	DeleteObject(oldFont);
	RECT _rc = RectMake(x, y, width, height); //넣을좌표

	DrawText(hdc, str, outputNum, &_rc, DT_LEFT | DT_WORDBREAK); //출력위치.

}

int  txtData::textSize(const char* loadFileName, HDC hdc) {
	
	HANDLE file;

	DWORD  dwTotalSize = 0;

	

	BOOL bResult;

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	dwTotalSize = GetFileSize(file, 0);
	CloseHandle(file);


	return dwTotalSize;
}