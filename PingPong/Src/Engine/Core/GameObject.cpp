#define _CRT_SECURE_NO_WARNINGS
#include "GameObject.h"
#include "Renderer.h"
#include <stdlib.h>

void GameObject::SetPos(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

void GameObject::Render()
{
	
}
void GameObject::ReadFile(const char* FilePath, char * &buff, int &fileSize)
{

}

string GameObject::GetTypeObject()
{
	return typeObject;
}


GameObject::GameObject()
{
	pos.x = 150;
	pos.y = 150;
	texture = NULL;
	info = SDL_Rect();
	frameID = 0;
}

GameObject::~GameObject()
{
}