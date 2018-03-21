#include "Ball.h"
#include "resource.h"
#include "Player.h"
#include "Enemy.h"
#include "Application.h"
#include "SceneManager.h"
#include "GameOverScene.h"
#include "GamePlayScene.h"


Ball::Ball()
{

}

Ball::~Ball()
{
}

void Ball::Update()
{
	SDL_Point pos = this->GetPos();
	
	Player* playerTemp = Resource::GetInstance()->gamePlayScene->GetPlayer();
	Enemy* enemyTemp = Resource::GetInstance()->gamePlayScene->GetEnemy();

	SDL_Point centerBall;
	centerBall.x = this->GetPos().x + this->GetWidth() / 2;
	centerBall.y = this->GetPos().y + this->GetHeight() / 2;

	SDL_Point centerPlayer;
	centerPlayer.x = playerTemp->GetPos().x + playerTemp->GetWidth() / 2;
	centerPlayer.y = playerTemp->GetPos().y + playerTemp->GetHeight() / 2;

	SDL_Point centerEnemy;
	centerEnemy.x = enemyTemp->GetPos().x + enemyTemp->GetWidth() / 2;
	centerEnemy.y = enemyTemp->GetPos().y + enemyTemp->GetHeight() / 2;
	//new
	//if ((centerBall.x + this->GetWidth() / 2 - 5) >= (centerEnemy.x - enemyTemp->GetWidth() / 2) 
	//	&& (centerBall.y + this->GetHeight() / 2 - 5) >= (centerEnemy.y - enemyTemp->GetHeight() / 2)
	//	&& (centerBall.y - this->GetHeight() / 2 + 5) <= (centerEnemy.y + enemyTemp->GetHeight() / 2))
	//{
	//	if (centerBall.y >= centerEnemy.y - enemyTemp->GetHeight() / 4 && centerBall.y <= centerEnemy.y + enemyTemp->GetHeight() / 4)
	//	{
	//		speed = 3;
	//		status = Left;
	//		angle = 30;
	//	}
	//	else
	//	{
	//		speed = 1;
	//		status = Left;
	//		angle = 45;
	//	}
	//}

	//if ((centerBall.x - this->GetWidth() / 2 + 5) <= (centerPlayer.x + playerTemp->GetWidth() / 2)
	//	&& (centerBall.y + this->GetHeight() / 2 - 5) >= (centerPlayer.y - playerTemp->GetHeight() / 2)
	//	&& (centerBall.y - this->GetHeight() / 2 + 5) <= (centerPlayer.y + playerTemp->GetHeight() / 2))
	//{
	//	if (centerBall.y >= centerPlayer.y - playerTemp->GetHeight() / 4 
	//		&& centerBall.y <= centerPlayer.y + playerTemp->GetHeight() / 4)
	//	{
	//		speed = 3;
	//		status = Right;
	//		angle = 30;
	//	}
	//	else
	//	{
	//		speed = 1;
	//		status = Right;
	//		angle = 45;
	//	}
	//}




	//if (status == Right  && pos.x <= Application::GetInstance()->GetWidth() - this->GetWidth())
	//{
	//	this->SetPos(pos.x + speed, pos.y);
	//}
	//
	/*if ((pos.x -2 == enemyTemp->GetPos().x - this->GetWidth())
		&&(((pos.y +this->GetHeight() - 1) >= enemyTemp->GetPos().y) && (pos.y <= (enemyTemp->GetPos().y+enemyTemp->GetHeight()  - 1))))
	{
		status = Left;
	} 
	if ((pos.x -2 == playerTemp->GetPos().x + playerTemp->GetWidth())
		&&((( pos.y+ this->GetHeight() - 1) >= playerTemp->GetPos().y) && (pos.y <= (playerTemp->GetPos().y + playerTemp->GetHeight()  - 1))))
	{
		status = Right;
	}*/
	//new
	/*if (status == Left && pos.x >=0)
	{
		this->SetPos(pos.x - speed, pos.y);
	}*/
	if (pos.x <=0 || pos.x >= Application::GetInstance()->GetWidth() - this->GetWidth())
	{
		Resource::GetInstance()->gameoverScene = new GameOverScene();
		Resource::GetInstance()->gameoverScene->Init();
		SceneManager::GetInstane()->NextScene(Resource::GetInstance()->gameoverScene);
	}
}
void Ball::Draw()
{
	Image::Draw();
}
void Ball::Init()
{
	this->SetFrameFromSprite(9, Resource::GetInstance()->sprite);
	this->SetPos(Application::GetInstance()->GetWidth()/2,Application::GetInstance()->GetHeight()/2);
	status = Right;
	speed = 3;

}
