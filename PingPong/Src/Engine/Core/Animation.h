#pragma once
#include "Image.h"
#include <SDL.h>


class Animation
{
public:
	Animation();
	~Animation();

private:
	Image* image;
	float deltaTime;
	int loop;
	int location;
	int runtimeFrame;
	bool flag;

};


