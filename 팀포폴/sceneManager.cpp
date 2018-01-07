#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"


sceneManager::sceneManager()
{
}


sceneManager::~sceneManager()
{
}

DWORD CALLBACK loadingThread(LPVOID prc)
{
	sceneManager::_readyScene->init();
	sceneManager::_currentScene = sceneManager::_readyScene;

	sceneManager::_loadingScene->release();
	sceneManager::_loadingScene = NULL;
	sceneManager::_readyScene = NULL;
	return 0;
}

gameNode* sceneManager::_currentScene = NULL;
gameNode* sceneManager::_loadingScene = NULL;
gameNode* sceneManager::_readyScene = NULL;
gameNode* sceneManager::_prevScene = NULL;

HRESULT sceneManager::init(void)
{
	_currentScene = NULL;
	_loadingScene = NULL;
	_readyScene = NULL;
	_prevScene = NULL;
	return S_OK;
}

void sceneManager::release(void)
{
	mapSceneIter miSceneList = _mSceneList.begin();

	for (; miSceneList != _mSceneList.end();)
	{
		if (miSceneList->second != NULL)
		{
			if (miSceneList->second == _currentScene) miSceneList->second->release();
			SAFE_DELETE(miSceneList->second);
			miSceneList = _mSceneList.erase(miSceneList);
		}
		else ++miSceneList;
	}
	_mSceneList.clear();
}

void sceneManager::update(void)
{
	if (_currentScene) _currentScene->update();
}

void sceneManager::render(void)
{
	if (_currentScene) _currentScene->render();
}

gameNode* sceneManager::addScene(string sceneName, gameNode* scene)
{
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

gameNode* sceneManager::addLoadingScene(string loadingSceneName, gameNode* scene)
{
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(loadingSceneName, scene));
	return scene;
}

HRESULT sceneManager::changeScene(string sceneName, player* p)
{
	mapSceneIter find = _mSceneList.find(sceneName);

	if (find == _mSceneList.end()) return E_FAIL;
	if (find->second == _currentScene)return S_OK;


	find->second->AddressLinkWithPlayer(p);
	bool k = SUCCEEDED(find->second->init());
	if (k)
	{
		if (_currentScene)_currentScene->release();
		_currentScene = find->second;
		

		return S_OK;
	}
	return E_FAIL;
}

HRESULT sceneManager::changeScene(string sceneName, string loadingSceneName, player* p)
{
	mapSceneIter find = _mSceneList.find(sceneName);

	if (find == _mSceneList.end()) return E_FAIL;
	if (find->second == _currentScene) return S_OK;

	mapSceneIter findLoading = _mLoadingSceneList.find(loadingSceneName);

	if (find == _mLoadingSceneList.end()) return changeScene(loadingSceneName,p);

	if (SUCCEEDED(find->second->init()))
	{
		if (_currentScene) _currentScene->release();

		_loadingScene = findLoading->second;
		_readyScene = find->second;
		CloseHandle(CreateThread(NULL, 0, loadingThread, NULL, 0, &_loadingThreadID));
	}

	return E_FAIL;
}

HRESULT sceneManager::tempScene(string sceneName)
{
	

	mapSceneIter find = _mSceneList.find(sceneName);

	if (find == _mSceneList.end()) return E_FAIL;
	if (find->second == _currentScene)return S_OK;
	

	bool k = SUCCEEDED(find->second->init());
	if (k)
	{
		_prevScene = _currentScene;
		_currentScene = find->second;
		return S_OK;
	}
	return E_FAIL;


}

HRESULT sceneManager::returnScene()
{
	_currentScene = _prevScene; 
	return S_OK; 
}

