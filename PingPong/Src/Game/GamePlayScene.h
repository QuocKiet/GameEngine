#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Ball.h"
#include "Player.h"
#include "Enemy.h"
#include "Box2D\Box2D.h"

class GamePlayScene : public Scene
{
public:
	void Init();
	void InitPhysicBall();
	void InitPhysicPlayer();
	void InitPhysicEnemy();
	void InitPhysicWallBot();
	void InitPhysicWallTop();
	void CheckPause();
	void UpdateBall();
	void UpdatePlayer();
	void UpdateEnemy();
	void Update();
	Ball* GetBall();
	Player* GetPlayer();
	Enemy* GetEnemy();
	GamePlayScene();
	~GamePlayScene();

private:
	Ball* ball;
	Player* player;
	Enemy* enemy;
	b2World* world;
	b2Body* bodyPlayer;
	b2Body* bodyEnemy;
	b2Body* bodyBall;
	b2Body* bodyWallTop;
	b2Body* bodyWallBot;
	//InfoPhysic ball;
	//InfoPhysic 
};

