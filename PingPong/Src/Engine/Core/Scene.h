#pragma once
#include "GameObject.h"
#include "Button.h"
#include <vector>
class Image;
//#include "Sprite.h"	
//#include <vector>
//#include "Header.h"
using namespace std;
class Scene
{
public:
	virtual void Update();
	virtual void Draw();
	virtual void Init() = 0;
	vector<GameObject*> GetListGameObject();
	void AddImage(Sprite* sp, int numFrame, int x, int y);
	void AddImage(Image* image);
	void Add(GameObject* gameObject);
	void RotateImage(int numImage, int x, int y, float o);
	Scene();
	~Scene();

protected:
	vector<GameObject*> listGameObject;
};

