#include "GameOverScene.h"
#include "resource.h"
#include "SceneManager.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}
void GameOverScene::Init()
{
	btnContinute = new Button();
	btnContinute->SetFrameFromSprite(1, Resource::GetInstance()->sprite);
	btnContinute->SetPos(130, 45);
	this->Add(btnContinute);
	btnContinute->setCallback(std::bind(&GameOverScene::OnClickBtnContinute, this));

	btnExit = new Button();
	btnExit->SetFrameFromSprite(3, Resource::GetInstance()->sprite);
	btnExit->SetPos(130, 155);
	this->Add(btnExit);
	btnExit->setCallback(std::bind(&GameOverScene::OnClickBtnExit, this));
}

void GameOverScene::OnClickBtnContinute()
{
	if (btnContinute->GetIsClick() == true)
	{
		btnContinute->SetFrameFromSprite(2, Resource::GetInstance()->sprite);
		Resource::GetInstance()->gamePlayScene = new GamePlayScene();
		Resource::GetInstance()->gamePlayScene->Init();
		SceneManager::GetInstane()->NextScene(Resource::GetInstance()->gamePlayScene);
	}
}

void GameOverScene::OnClickBtnExit()
{
	if (btnExit->GetIsClick() == true)
		Application::GetInstance()->SetIsRunning(false);
}

//void GameOverScene::Update()
//{
//	for (int i = 0; i < listGameObject.size(); i++)
//	{
//		listGameObject[i]->Update();
//		listGameObject[i]->Draw();
//	}
//}