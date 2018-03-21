#include "Image.h"
#include "Sprite.h"
#include <vector>
#include "Renderer.h"
#include "EventManager.h"

void Image::Rotate(int x, int y, float o)
{
	center.x = x;
	center.y = y;
	angle =o;
}
void Image::Draw()
{
	SDL_Rect srcrect;
	SDL_Rect desrect;
	//SDL_QueryTexture(texture, NULL, NULL, &srcrect.w, &srcrect.h);
	srcrect.w = info.w;
	srcrect.h = info.h;
	desrect.x = pos.x;
	desrect.y = pos.y;
	desrect.w = info.w;
	desrect.h = info.h;
	srcrect.x = info.x;
	srcrect.y = info.y;
	SDL_RenderCopyEx(Renderer::GetInstance()->Getrenderer(), texture, &srcrect, &desrect, angle, &center, SDL_FLIP_NONE);

}
void Image::SetFrameFromSprite(int numFrame, Sprite* sprite)
{
	info = sprite->listFrame[numFrame-1];
	center.x = info.w / 2;
	texture = sprite->GetTexture();
	center.y = info.h / 2;
}



void Image::Update()
{

}

Image::Image()
{
	this->info.x = 0;
	this->info.y = 0;
	this->pos.x = 0;
	this->pos.y = 0;
	this->center.x = 0;
	this->center.y = 0;
	this->frameID = 0;
	this->texture = NULL;
	angle = 0;
	typeObject = "Image";
}

Image::~Image()
{
}