#pragma once
#include "Scene.h"



class MenuScene :public Scene
{
public:

	void Init();
	//void Render();
	//void Update();
	//void Exit() {};

	void OnMouseDownBtnStart();
	void OnMouseDownBtnMute();
	void OnMouseDownBtnExit();
	MenuScene();
	~MenuScene();
private:
	Button* btnStart;
	Button* btnMute;
	Button* btnExit;
	//Sprite * sprite= new Sprite("spr_data.cnf", "spr_data.png");
	
};
