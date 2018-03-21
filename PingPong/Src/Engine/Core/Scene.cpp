#include "Scene.h"
#include "Sprite.h"
#include "Image.h"


vector<GameObject*> Scene::GetListGameObject()
{
	return listGameObject;
}
void Scene::RotateImage(int numImage, int x, int y, float o)
{
	listGameObject[numImage - 1]->Rotate(x, y, o);
}
void Scene::Draw()
{
	for (vector<GameObject*>::iterator it = listGameObject.begin(); it != listGameObject.end(); it++)
	{
		(*it)->Draw();
	}
}

void Scene::Update()
{
	for (int i = 0; i < listGameObject.size(); i++)
	{
		listGameObject[i]->Update();
		listGameObject[i]->Draw();
	}
}

void Scene::AddImage(Sprite* sp, int numFrame, int x, int y)
{
	/*Sprite SpriteTemp;
	SpriteTemp.SetPos(x, y);
	SpriteTemp.Load(pathImage);
	SpriteTemp.LoadwWithFile(pathFie,numFrame);
	listSprite.push_back(&SpriteTemp);*/
	Image* image = new Image();
	image->SetFrameFromSprite(numFrame, sp);
	image->SetPos(x, y);
	listGameObject.push_back(image);
}
void Scene::AddImage(Image* image)
{
	listGameObject.push_back(image);
}

void Scene::Add(GameObject* gameObject)
{
	listGameObject.push_back(gameObject);
}
Scene::Scene()
{

}

Scene::~Scene()
{
}