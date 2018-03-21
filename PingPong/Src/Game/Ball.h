#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Box2D\Box2D.h"

enum Status
{
	Left, Right
};
class Ball :public Image
{
public:
	void Init();
	void Update();
	void Draw();
	Ball();
	~Ball();

private:
	Status status;
	int speed;
	int angle;
	b2Vec2 velocity;
};

