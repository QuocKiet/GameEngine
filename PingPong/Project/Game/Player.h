#pragma once
#include "Image.h"

class Player : public Image
{
public:
	void Init();
	void Update();
	void Draw();
	Player();
	~Player();

private:
	Sprite * sprite = new Sprite("spr_data.cnf", "spr_data.png");
};
