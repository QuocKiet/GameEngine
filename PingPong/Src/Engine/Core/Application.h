#pragma once
//#include "Header.h"
#include <SDL.h>
#include <stdio.h>
#include "Scene.h"
#include <time.h>
#include"../../Src/Game/resource.h"
//#include <stdio.h>
//#include "Renderer.h"
//#include "GameObject.h"
//#include "Sprite.h"
//#include "Scene.h"
class Application
{
public:
	clock_t deltatime;
    static Application* GetInstance();
    bool Init(char* name, int width, int height);
    void Render();
	void Run(int);
	void Clean();
	void Update();
	Application(char* name, int width, int height);
	int GetWidth();
	int GetHeight();
	SDL_Window* GetWindow();
	void SetIsRunning(bool);
	bool GetRunning();
	Application();
	~Application();

private:
	static Application* m_ins;
	static SDL_Window* window;
	//static SDL_Renderer* renderer;
    static bool isRunning;
private:
	char* Name;
	int Width;
	int Height;
	int fps;
	clock_t delayTime;
	
};

