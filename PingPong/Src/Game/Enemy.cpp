#include "Enemy.h"
#include "resource.h"
#include "EventManager.h"
#include "Application.h"

void Enemy::Init()
{
	this->SetFrameFromSprite(11, Resource::GetInstance()->sprite);
	this->SetPos(Application::GetInstance()->GetWidth()-this->GetWidth(), Application::GetInstance()->GetHeight() / 2 - this->GetHeight() / 2);
	/*
	b2PolygonShape polygonShape;
	polygonShape.SetAsBox(this->info.w / 2, this->info.h / 2);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;
	fixtureDef.density = 2.0;
	fixtureDef.friction = 1.0;
	fixtureDef.restitution = 1.0;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(this->pos.x, this->pos.y);
	bodyDef.angle = 0;

	body = Resource::GetInstance()->world->CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);
*/
}
void Enemy::Update()
{
	SDL_Point pos = this->GetPos();
	if (EventManager::GetInstance()->IsKeyDown(111) == true)
	{
		if (pos.y >0)
			this->SetPos(pos.x, this->pos.y - 3);
	}
	if (EventManager::GetInstance()->IsKeyDown(108) == true)
	{
		if (pos.y < (Application::GetInstance()->GetHeight() - this->GetHeight()))
			this->SetPos(pos.x, pos.y + 3);
	}
}

void Enemy::Draw()
{
	Image::Draw();
}
Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}