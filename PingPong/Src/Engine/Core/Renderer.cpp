#include "Renderer.h"
#include "Application.h"
#include "Image.h"
#include "SceneManager.h"

//SDL_Renderer* Renderer::renderer = NULL;
Renderer* Renderer::ins = NULL;

//Image* Renderer::LoadImage(const char* path)
//{	
//	Image* image = new Image();
//	SDL_Texture* a = IMG_LoadTexture(renderer,path);
//	return image;
//}

SDL_Renderer* Renderer::Getrenderer()
{
	return renderer;
}
void Renderer::Render()
{
	SDL_RenderPresent(renderer);
}

void Renderer::Init(SDL_Window* window)
{

	renderer = SDL_CreateRenderer(Application::GetInstance()->GetWindow(), -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
		printf("Render\n");
	
}

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}
