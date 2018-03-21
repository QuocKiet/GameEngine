#include "Text.h"
#include <string>
#include "Renderer.h"

using namespace std;

Text::Text()
{
	color.a = 0;
	color.b = 0;
	color.g = 0;
	color.r = 0;
	font = NULL;
	fontFormat = NULL;
	pos.x = 0;
	pos.y = 0;
	info.h = 0;
	info.w = 0;
	info.x = 0;
	info.y = 0;
	texture = NULL;
	fontSize = 0;
	surface = NULL;
}

Text::~Text()
{
	SDL_DestroyTexture(texture);
}

void Text::SetColor(int r, int g, int b, int a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

void Text::SetFontSize(int size)
{
	fontSize = size;
}

void Text::SetFontFormat(const char* format)
{
	fontFormat = format;
}

void Text::CreateText(const char* text)
{
	font = TTF_OpenFont(fontFormat, fontSize);
	string Text = text;
	surface = TTF_RenderText_Solid(font, Text.c_str(), color);
	texture = SDL_CreateTextureFromSurface(Renderer::GetInstance()->Getrenderer(), surface);
	SDL_FreeSurface(surface);
	TTF_SizeText(font, Text.c_str(), &info.w, &info.h);
}

void Text::SetPos(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

void Text::Draw()
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
	SDL_RenderCopy(Renderer::GetInstance()->Getrenderer(), texture, &srcrect, &desrect);
}

void Text::Render()
{
	SDL_RenderPresent(Renderer::GetInstance()->Getrenderer());
}