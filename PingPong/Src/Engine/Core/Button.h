#pragma once
#include "GameObject.h"
#include "Image.h"
#include <functional>
//#include "EventManager.h"
//#include <SDL.h>
//#include "Header.h"

class Button : public GameObject
{
public:
	void LoadwWithFile(const char* filepath, int i);
	void Draw();
	//bool Clicked();
	int GetWidth();
	int GetHeight();
	SDL_Point GetPos();
	void SetFrameFromSprite(int numFrame, Sprite *sp);
	void SetPos(int x, int y);
	bool GetIsClick();
	string GetTypeObject();
	void SetIsClick(bool);
	bool GetCheck();
	void Update();
	//void SetFrame();
	void setCallback(std::function<void()> func)
	{
		funtion = func;
	}

	void Click()
	{
		funtion();
	}

	Button();
	~Button();

private:
	std::function<void()> funtion;
	bool check = false;
	bool isClick;
	Image* imageButton;


};

