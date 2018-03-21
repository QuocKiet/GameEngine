#include "resource.h"
#include "Application.h"
#include "SceneManager.h"
#include "Ball.h"
#include "Player.h"
#include "Enemy.h"
#include "GameOverScene.h"
Resource* Resource::instance = NULL;

void Resource::Delete()
{
	delete gamePlayScene;
}
void Resource::Init()
{
	Application::GetInstance()->Init("KIET",500,350);
	sprite = sprite = new Sprite("spr_data.cnf", "spr_data.png");

	gamePlayScene = new GamePlayScene();
	gamePlayScene->Init();

	pauseScene = new PauseScene();
	pauseScene->Init();

	menuScene = new MenuScene();
	menuScene->Init();
	
	gameoverScene = new GameOverScene();
	gameoverScene->Init();

	SceneManager::GetInstane()->SetStartScene(menuScene);
}

Resource::Resource()
{
	
}

Resource::~Resource()
{
	delete sprite;
	delete menuScene;
	delete gamePlayScene;
	delete pauseScene;
}