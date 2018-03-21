#include "GamePlayScene.h"
#include "resource.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Application.h"
#include <string>

using namespace std;
struct InfoPhysic
{
	string namePhysic;
};


GamePlayScene::GamePlayScene()
{
	ball = NULL;
	player = NULL;
	enemy = NULL;
	bodyPlayer = NULL;
	bodyEnemy = NULL;
	bodyBall = NULL;
	bodyWallBot = NULL;
	bodyWallTop = NULL;
}

GamePlayScene::~GamePlayScene()
{

}

void GamePlayScene::InitPhysicBall()
{
	b2CircleShape circleShape;
	circleShape.m_radius = (float)this->ball->GetHeight() / 2;
//
	
	b2FixtureDef fixtureDefBall;
	fixtureDefBall.shape = &circleShape;
	fixtureDefBall.density = 0.0f;
	fixtureDefBall.restitution = 1.0f;
	fixtureDefBall.friction = 100.0f;
	

	b2BodyDef bodyDefBall;
	bodyDefBall.type = b2_dynamicBody;
	bodyDefBall.position.Set((float)this->ball->GetPos().x, (float)this->ball->GetPos().y);
	bodyDefBall.angle = 80.0f;
	//bodyDefBall.gravityScale = 0.0f;

	
	bodyBall = world->CreateBody(&bodyDefBall);
	bodyBall->CreateFixture(&fixtureDefBall);
	//b2Vec2 impulse(0.0f, 1010000.0f);
	//b2Vec2 Offset(1.0f, 0.0f);

	//bodyBall->ApplyForce(impulse, Offset, true);
	bodyBall->SetLinearVelocity(b2Vec2(1000.0f,0.0f));
}

void GamePlayScene::InitPhysicPlayer()
{
	b2PolygonShape polygonShape1;
	polygonShape1.SetAsBox((float)this->player->GetWidth() / 2, (float)this->player->GetHeight() / 2);

	b2FixtureDef fixtureDefPlayer;
	fixtureDefPlayer.shape = &polygonShape1;
	fixtureDefPlayer.restitution = 1.0f;
	fixtureDefPlayer.friction = 100.0f;


	b2BodyDef bodyDefPlayer;
	bodyDefPlayer.type = b2_staticBody;
	bodyDefPlayer.position.Set(10.0, 10.0);
	//bodyDefPlayer.angle = 0;

	bodyPlayer = world->CreateBody(&bodyDefPlayer);
	bodyPlayer->CreateFixture(&fixtureDefPlayer);

}

void GamePlayScene::InitPhysicEnemy()
{
	b2PolygonShape polygonShape2;
	polygonShape2.SetAsBox((float)this->enemy->GetWidth() / 2, (float)this->enemy->GetHeight() / 2);

	b2FixtureDef fixtureDefEnemy;
	fixtureDefEnemy.shape = &polygonShape2;
	fixtureDefEnemy.restitution = 1.0f;
	fixtureDefEnemy.friction = 100.0f;
	b2BodyDef bodyDefEnemy;
	bodyDefEnemy.type = b2_staticBody;
	bodyDefEnemy.position.Set(50, 50);
	//bodyDefEnemy.angle = 90.0;

	bodyEnemy = world->CreateBody(&bodyDefEnemy);
	bodyEnemy->CreateFixture(&fixtureDefEnemy);

}

void GamePlayScene::Init()
{
	ball = new Ball();
	ball->Init();
	this->Add(ball);
	
	player = new Player();
	player->Init();
	this->Add(player);

	enemy = new Enemy();
	enemy->Init();
	this->Add(enemy);
	b2Vec2 gravity(0.0f,0.0f);
	world = new b2World(gravity);
	this->InitPhysicBall();
	this->InitPhysicPlayer();
	this->InitPhysicEnemy();
	this->InitPhysicWallBot();
	this->InitPhysicWallTop();
	
	
}

Ball* GamePlayScene::GetBall()
{
	return ball;
}

Player* GamePlayScene::GetPlayer()
{
	return player;
}

Enemy* GamePlayScene::GetEnemy()
{
	return enemy;
}

void GamePlayScene::UpdateBall()
{
	b2Vec2 vec2Ball = this->bodyBall->GetPosition();
	this->ball->SetPos((int)vec2Ball.x - this->ball->GetWidth() / 2, (int)vec2Ball.y - this->ball->GetHeight() / 2);

}

void GamePlayScene::UpdatePlayer()
{
	//b2Vec2 vec2Player = this->bodyPlayer->GetPosition();
	bodyPlayer->SetTransform(b2Vec2((float)this->player->GetPos().x + (float)this->player->GetWidth() / 2,
									(float)this->player->GetPos().y + ((float)this->player->GetHeight() / 2)), 0);
}

void GamePlayScene::UpdateEnemy()
{
	//b2Vec2 vec2Enemy = this->bodyEnemy->GetPosition();
	bodyEnemy->SetTransform(b2Vec2((float)this->enemy->GetPos().x + (float)this->enemy->GetWidth() / 2,
									(float)this->enemy->GetPos().y + (float)this->enemy->GetHeight() / 2), 0);
}

void GamePlayScene::InitPhysicWallBot()
{
	b2EdgeShape edgeShape;
	edgeShape.Set(b2Vec2(0.0,(float)Application::GetInstance()->GetHeight()), b2Vec2((float)Application::GetInstance()->GetWidth(),(float)Application::GetInstance()->GetHeight()));
	b2FixtureDef fixterEdge;
	fixterEdge.shape = &edgeShape;
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	fixterEdge.restitution = 1.0f;
	bodyWallBot = world->CreateBody(&bodyDef);
	bodyWallBot->CreateFixture(&fixterEdge);
}

void GamePlayScene::InitPhysicWallTop()
{
	b2EdgeShape edgeShape;
	edgeShape.Set(b2Vec2(0.0, 2.0), b2Vec2((float)Application::GetInstance()->GetWidth(), 2.0));
	b2FixtureDef fixterEdge; 
	fixterEdge.shape = &edgeShape;
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	fixterEdge.restitution = 1.0f;
	bodyWallTop = world->CreateBody(&bodyDef);
	bodyWallTop->CreateFixture(&fixterEdge);
}

void GamePlayScene::Update()
{

	world->Step(1.0f/60.0f,8.0f,3.0f);
	UpdateBall();
	UpdatePlayer();
	UpdateEnemy();

	for (int i = 0; i < listGameObject.size(); i++)
	{
		listGameObject[i]->Update();
		listGameObject[i]->Draw();
	}
	this->CheckPause();
}
void GamePlayScene::CheckPause()
{
	if (EventManager::GetInstance()->IsKeyDown(27) == true)
	{
		Resource::GetInstance()->pauseScene = new PauseScene();
		Resource::GetInstance()->pauseScene->Init();
		SceneManager::GetInstane()->NextScene(Resource::GetInstance()->pauseScene);
	}
}