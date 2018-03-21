#pragma once
#include "Sprite.h"
#include "MenuScene.h"
#include "GamePlayScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"
#include "Box2D\Box2D.h"



class Resource
{
public:
	GamePlayScene* gamePlayScene;
	PauseScene* pauseScene;
	MenuScene* menuScene;
	GameOverScene* gameoverScene;
	Sprite* sprite;
	void Delete();
	float timeStep = 1 / 60.0f;
	static Resource* GetInstance()
	{
		if (instance == NULL)
			instance = new Resource();

		return instance;
	}
	void Init();
	Resource();
	~Resource();

private:
	static Resource* instance;

};

