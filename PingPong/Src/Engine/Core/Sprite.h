#pragma once
#include "GameObject.h"
#include <stdio.h>
#include <vector>
//#include "Header.h"
using namespace std;
class Sprite : public GameObject
	
{
	friend class Image;
	vector <SDL_Rect> listFrame;
	const char* path;
public:
	void Update() {  };
	void Draw() {};
	SDL_Texture* GetTexture();
	void ReadFile(const char* FilePath, char * &buff, int &fileSize);
	void GetInfoFrame(const char* path, int FrameID);
	bool Load(const char* path);
	void SetPos(int x, int y);
	SDL_Rect GetFrame(int);
	Sprite(const char* FilePath,const char* PathImage);
	Sprite();
	~Sprite();
};

