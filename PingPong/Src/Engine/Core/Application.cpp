#include "Application.h"
#include <SDL_ttf.h>
#include "Renderer.h"
#include "SceneManager.h"
#include <time.h>

Application* Application::m_ins = nullptr;
SDL_Window* Application::window = NULL;
bool Application::isRunning = true;

Application::Application(char* name, int width, int height)
{
	Name = name;
	Width = width;
	Height = height;

	if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
		return ;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Unable to initialize SDL %s\n", SDL_GetError());
		return;
	}

	window = SDL_CreateWindow(Name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Could not create window %s", SDL_GetError());
		return ;
	}

	Renderer::GetInstance()->Init(window);

	return;

}


SDL_Window* Application::GetWindow()
{
	return window;
}

bool Application::Init(char* name, int width, int height)
{
	Name = name;
	Width = width;
	Height = height;
	if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
		return 0;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Unable to initialize SDL %s\n", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow(Name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Could not create window %s", SDL_GetError());
		return false;
	}

	Renderer::GetInstance()->Init(window);
	SDL_SetRenderDrawColor(Renderer::GetInstance()->Getrenderer(), 255, 255, 255, 255);
	return true;

}
int Application::GetWidth()
{
	return Width;
}
int Application::GetHeight()
{
	return Height;
}

void Application::Update()
{
	//SDL_RenderClear(Renderer::GetInstance()->Getrenderer());
	SceneManager::GetInstane()->Update();
	//SceneManager::GetInstane()->Draw();
}

bool Application::GetRunning()
{
	return isRunning;
}

Application* Application::GetInstance()
{
	if (m_ins == NULL)
		m_ins = new Application();

	return m_ins;
}

void Application::SetIsRunning(bool b)
{
	isRunning = b;
}

Application::~Application()
{

}
Application::Application()
{
	
}
void Application::Run(int FPS)
{	
	fps = FPS;
	delayTime = 1000 / fps;
	clock_t start, finish,debug ,debug1;
	int count = 0;
	debug1 = clock();
	int temp;
	while (isRunning==true)
	{
		
		count++;
		
		if (count == 60)
		{
			debug = clock();
			temp = debug - debug1;
			debug1 = debug;
			printf("%d\n", temp);
			count = 0;
		}
		start = clock();
		EventManager::GetInstance()->ProcessEvent();
		SDL_RenderClear(Renderer::GetInstance()->Getrenderer());
		Update();
		Render();
		finish = clock();
		deltatime = (finish - start);
	//	printf("%f\n", deltatime);
		if (deltatime < delayTime)
		{
			SDL_Delay(delayTime - deltatime);
			//printf("Delay: %ld\n",(delayTime - deltatime));
			//deltatime = delayTime;
		}
		else
		{
			printf("\tNo Delay\n");
		}
		//SDL_Delay((float)1000 / (float)60);
	}
}

void Application::Render()
{
	Renderer::GetInstance()->Render();
}
void Application::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Renderer::GetInstance()->Getrenderer());
	SDL_Quit();
	TTF_Quit();
}

