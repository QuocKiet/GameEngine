#pragma once

#include "Header.h"
#include "SingleTon.h"
#include "Test.h"
#include "MenuScene.h"
#include "resource.h"
#include <Box2D\Box2D.h>
#include "Image.h"
#include "Sprite.h"

int main(int argc, char *argv[])
{
	
	Resource::GetInstance()->Init();
	Application::GetInstance()->Run(60);	
	return 0;
}