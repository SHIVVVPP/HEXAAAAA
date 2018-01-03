#pragma once
#include "singletonBase.h"
#include <string>
#include <map>

class gameNode;
class player;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*> mapSceneList;
	typedef map<string, gameNode*>::iterator mapSceneIter;

private:
	static gameNode* _currentScene;
	static gameNode* _loadingScene;
	static gameNode* _readyScene;
	static gameNode* _preScene;


	mapSceneList _mSceneList;
	mapSceneList _mLoadingSceneList;

	DWORD _loadingThreadID;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	gameNode* addScene(string sceneName, gameNode* scene);
	gameNode* addLoadingScene(string loadingSceneName, gameNode* scene);

	HRESULT changeScene(string sceneName, player* p);
	HRESULT changeScene(string sceneName, string loadingSceneName, player* p);
	HRESULT returnScene();

	friend DWORD CALLBACK loadingThread(LPVOID prc);
	sceneManager();
	~sceneManager();

	HRESULT changeScene(string sceneName);
	HRESULT changeScene(string sceneName,string loadingSceneName);
};

