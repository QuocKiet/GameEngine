#include "Button.h"
#include "EventManager.h"
#include "Renderer.h"


void Button::Update()
{
	this->Click();
}
void Button::LoadwWithFile(const char* filepath, int i)
{
	//GameObject::LoadwWithFile(filepath, i);
}


void Button::SetIsClick(bool set)
{
	isClick = set;
}


bool Button::GetCheck()
{
	return check;
}



void Button::Draw()
{
	imageButton->Draw();
}

int Button::GetWidth()
{
	return info.w;
}

int Button::GetHeight()
{
	return info.h;
}

SDL_Point Button::GetPos()
{
	return pos;
}


bool Button::GetIsClick()
{
	return isClick;
}

void Button::SetFrameFromSprite(int numFrame, Sprite* sp)
{
	imageButton->SetFrameFromSprite(numFrame, sp);
	pos = imageButton->GetPos();
	info = imageButton->GetInfo();
}

void Button::SetPos(int x, int y)
{
	pos.x = x;
	pos.y = y;
	imageButton->SetPos(x, y);
}

string Button::GetTypeObject()
{
	return typeObject;
}

Button::Button()
{
	imageButton = new Image;
	typeObject = "Button";
	isClick = false;
	funtion = NULL;
}

Button::~Button()
{
}