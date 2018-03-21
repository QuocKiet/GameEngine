#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//#include "Renderer.h"
//#include "Header.h"

using namespace std;
class Sprite;
class GameObject
{
public:
	//virtual void Load(int x, int y, int width, int height, string textureline);
	virtual void LoadTexture(Sprite*) {};
	virtual void Render();
	virtual void Draw() = 0;
	virtual void SetFrameFromSprite(int numFrame, Sprite* sprite) {};
	void ReadFile(const char* FilePath, char * &buff, int &fileSize);
	int GetWidth() { return info.w;};
	int GetHeight() { return info.h; };
	SDL_Point GetPos() { return pos; };
	void SetPos(int x, int y);
	SDL_Rect GetInfo()
	{
		return info;
	}

	virtual void Rotate(int x, int y, float o) {};
	virtual string GetTypeObject();
	virtual void SetIsClick(bool){};
	virtual bool GetIsClick() {	return true;};
	virtual void Update() = 0;
	GameObject();
	~GameObject();

protected:
	SDL_Texture* texture;
	SDL_Point pos;
	SDL_Rect info;
	int frameID;
	string typeObject;
	 
};

