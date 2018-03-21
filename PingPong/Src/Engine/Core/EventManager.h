#pragma once
#include <SDL.h>
#include <stdio.h>
//#include "Header.h"
//enum Status
//{
//	Left, Right
//};
class EventManager
{
public:
	static EventManager* GetInstance();
	SDL_Point GetMousePos();
	bool GetMouseState(int);
	void ProcessEvent();
	bool IsMouseButtonDown(int MouseButton);
	bool IsMouseButtonUp(int MouseButton);
	//SDL_Point GetMousePos();
	bool IsKeyDown(int key);	
	bool IsKeyUp(int key);
//	Status Getstatus();
	EventManager();
	~EventManager();

private:
	SDL_Point mousePosition;
	bool mouseState[3];
	bool keyState[256];
	static EventManager* Instance;
	//Status status;
	
	
};

