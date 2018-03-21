#pragma once
#include "GameObject.h"
#include <SDL_ttf.h>

class Text : public GameObject
{
public:
	
	void SetColor(int, int, int, int);
	void SetFontSize(int);
	void SetFontFormat(const char*);
	void CreateText(const char* text);
	void SetPos(int, int);
	void Draw();
	void Render();

	Text();
	~Text();
private:
	SDL_Color color;
	TTF_Font* font;
	const char* fontFormat;
	int fontSize;
	SDL_Surface* surface;

};

