#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <SDL.h>
#include "Sprite.h"

class Image : public GameObject
{
	friend class Renderer;
public:
	void Draw();
	void Update();
	void SetFrameFromSprite(int numFrame, Sprite* sprite);
	void Rotate(int x, int y, float o);
	bool GetIsClick() { return true; };
	Image();
	~Image();

private:
	//SDL_Texture* texture;
	SDL_Point center;
	float angle;
};

