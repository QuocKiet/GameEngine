#pragma once
#include <SDL.h>
#include "SingleTon.h"
//#include <SDL_image.h>
//#include "Image.h"
//#include <string>
//#include "Application.h"
//#include "Header.h"
using namespace std;
class Renderer
{
public:
	void Init(SDL_Window*);
	void Render();
	SDL_Renderer* Getrenderer();
	static Renderer* GetInstance()
	{
		
		if (ins == NULL)
		{
			ins = new Renderer();
		}
		return ins;
	}
	Renderer();
	~Renderer();

private:
	static Renderer* ins;
	SDL_Renderer* renderer;


};

