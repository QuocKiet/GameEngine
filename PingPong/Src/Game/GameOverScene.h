#pragma once
#include "Scene.h"

class GameOverScene :public Scene
{
public:
	GameOverScene();
	~GameOverScene();
	void Init();
	void OnClickBtnContinute();
	void OnClickBtnExit();

private:
	Button* btnContinute;
	Button* btnExit;

};

