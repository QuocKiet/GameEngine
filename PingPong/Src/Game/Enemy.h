#pragma once
#include "Image.h"

class Enemy : public Image
{
public:
	void Init();
	void Update();
	void Draw();
	Enemy();
	~Enemy();

private:
};