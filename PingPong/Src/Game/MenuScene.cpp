#include "MenuScene.h"
#include <functional>
#include "resource.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "GamePlayScene.h"

MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::OnMouseDownBtnStart()
{
	if (btnStart->GetIsClick() == true)
	{
		btnStart->SetFrameFromSprite(2, Resource::GetInstance()->sprite);
		SceneManager::GetInstane()->NextScene(Resource::GetInstance()->gamePlayScene);

	}
	else
	{
		btnStart->SetFrameFromSprite(1, Resource::GetInstance()->sprite);
	}
	
	
}

void MenuScene::OnMouseDownBtnMute()
{
	if (btnMute->GetIsClick() == true)
	{
		btnMute->SetFrameFromSprite(6, Resource::GetInstance()->sprite);
	}
	else
	{
		btnMute->SetFrameFromSprite(5, Resource::GetInstance()->sprite);
	}
}

void MenuScene::OnMouseDownBtnExit()
{
	if (btnExit->GetIsClick() == true)
	{
		btnExit->SetFrameFromSprite(4, Resource::GetInstance()->sprite);
		Application::GetInstance()->SetIsRunning(false);
	}
	else
	{
		btnExit->SetFrameFromSprite(3, Resource::GetInstance()->sprite);
	}

}


void MenuScene::Init()
{
	
	btnStart = new Button();
	btnStart->SetPos(130, 45);
	btnStart->SetFrameFromSprite(1, Resource::GetInstance()->sprite);
	this->Add(btnStart);
	btnStart->setCallback(std::bind(&MenuScene::OnMouseDownBtnStart,this));


	btnMute = new Button();
	btnMute->SetPos(230, 265);
	btnMute->SetFrameFromSprite(5, Resource::GetInstance()->sprite);
	this->Add(btnMute);
	btnMute->setCallback(std::bind(&MenuScene::OnMouseDownBtnMute, this));

	btnExit = new Button();
	btnExit->SetPos(130,155);
	btnExit->SetFrameFromSprite(3, Resource::GetInstance()->sprite);
	this->Add(btnExit);

	btnExit->setCallback(std::bind(&MenuScene::OnMouseDownBtnExit, this));
	
}
//void MenuScene::Render()
//{
//	for (int i = 0; i < listGameObject.size(); i++)
//	{
//		listGameObject[i]->Render();
//	}
//}

//void MenuScene::Update()
//{
//	for (int i = 0; i < listGameObject.size(); i++)
//	{
//		listGameObject[i]->Update();
//		listGameObject[i]->Draw();
//	}
//
//}