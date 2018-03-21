#include "Enemy.h"
#include "resource.h"
#include "EventManager.h"
#include "Application.h"

void Enemy::Init()
{
	this->SetFrameFromSprite(11, Resource::GetInstance()->sprite);
	this->SetPos(160, 1);
}
void Enemy::Update()
{

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