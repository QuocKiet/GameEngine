#pragma once
#pragma once
#include "Scene.h"

class PauseScene :public Scene
{
public:
	PauseScene();
	~PauseScene();
	void Init();
	void OnClickBtnContinute();
	//void Update();
	void OnClickBtnExit();

private:
	Button* btncontinute;
	Button* btnexit;
};


