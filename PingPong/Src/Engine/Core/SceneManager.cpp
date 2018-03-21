#include "SceneManager.h"
SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{
	nextScene = NULL;
	currenScene = NULL;
	prevScene = NULL;
}

SceneManager::~SceneManager()
{
}

Scene* SceneManager::GetCurrenScene()
{
	return currenScene;
}

void SceneManager::SetStartScene(Scene* startScene)
{
	currenScene = startScene;
}

void SceneManager::NextScene(Scene* _nextScene)
{
	nextScene = _nextScene;
}

void SceneManager::Draw()
{
	currenScene->Draw();
}
void SceneManager::Render()
{
	
}

void SceneManager::Update()
{
	//if (nextScene != NULL)
	//{
	//	currenScene = nextScene;
	//}
	//currenScene->Update();
	////currenScene->Draw();
	if (nextScene == NULL)
	{
		currenScene->Update();
	}
	else
	{
		currenScene = nextScene;
		nextScene = NULL;
	}
}
