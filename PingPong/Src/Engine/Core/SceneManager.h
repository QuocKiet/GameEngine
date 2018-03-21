#pragma once
//#include "Scene.h"
//#include <vector>
#include "Header.h"


using namespace std;
class SceneManager
{
public:
	static SceneManager* GetInstane()
	{
		if (instance == nullptr)
		{
			instance = new SceneManager();
		}
		return instance;
	}
	//void UpdateScene();
	void Render();
	void Draw();
	void Update();

	void SetStartScene(Scene* newscene);
	void NextScene(Scene* nextScene);
	Scene* GetCurrenScene();
	SceneManager();
	~SceneManager();

private:
	static SceneManager* instance;
	Scene* currenScene;
	Scene* nextScene;
	Scene* prevScene;
};

