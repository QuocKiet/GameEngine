
#include "Player.h"
#include "resource.h"
#include "EventManager.h"
#include "Application.h"


void Player::Init()
{
	this->SetFrameFromSprite(10, Resource::GetInstance()->sprite);
	this->SetPos(0, Application::GetInstance()->GetHeight() / 2 - this->GetHeight() / 2);
	
}
void Player::Update()
{
	SDL_Point pos = this->GetPos();
	if (EventManager::GetInstance()->IsKeyDown(119) == true)
	{
		if (pos.y > 0)
			this->SetPos(pos.x, pos.y - 3);
	}
	if (EventManager::GetInstance()->IsKeyDown(115) == true)
	{
		if (pos.y < (Application::GetInstance()->GetHeight() - this->GetHeight()))
			this->SetPos(pos.x,pos.y + 3);
	}
}

void Player::Draw()
{
	Image::Draw();
}
Player::Player()
{
}

Player::~Player()
{
}