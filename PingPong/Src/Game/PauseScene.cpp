#include "PauseScene.h"
#include "resource.h"
#include "SceneManager.h"
PauseScene::PauseScene()
{

}

PauseScene::~PauseScene()
{

}
//void PauseScene::Update()
//{
//	for (int i = 0; i < listGameObject.size(); i++)
//	{
//		listGameObject[i]->Update();
//		listGameObject[i]->Draw();
//	}
//}
void PauseScene::Init()
{
	btncontinute = new Button();
	btncontinute->SetFrameFromSprite(1,Resource::GetInstance()->sprite );
	btncontinute->SetPos(130,45);
	this->Add(btncontinute);
	btncontinute->setCallback(std::bind(&PauseScene::OnClickBtnContinute, this));

	btnexit = new Button();
	btnexit->SetFrameFromSprite(3, Resource::GetInstance()->sprite);
	btnexit->SetPos(130, 155);
	this->Add(btnexit);
	btnexit->setCallback(std::bind(&PauseScene::OnClickBtnExit, this));

}

void PauseScene::OnClickBtnContinute()
{
	if (btncontinute->GetIsClick() == true)
	{
		btncontinute->SetFrameFromSprite(2, Resource::GetInstance()->sprite);
		SceneManager::GetInstane()->NextScene(Resource::GetInstance()->gamePlayScene);
	}
}

void PauseScene::OnClickBtnExit()
{
	if (btnexit->GetIsClick() == true)
	{
		btnexit->SetFrameFromSprite(4, Resource::GetInstance()->sprite);
		Application::GetInstance()->SetIsRunning(false);
	}
}