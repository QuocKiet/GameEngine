#define _CRT_SECURE_NO_WARNINGS
#include "Sprite.h"
#include "Renderer.h"
#include "Image.h"
using namespace std;

SDL_Rect Sprite::GetFrame(int n)
{
	return listFrame[n];
}
//void Sprite::Create(int x, int y, int widht, int height, const char* path)
//{
//	GameObject::Create(x, y, widht, height, path);
//	printf("Sprite create\n");
//}
void Sprite::SetPos(int x, int y)
{
	
}

Sprite::Sprite(const char* pathfile, const char* pathimage)
{
	this->Load(pathimage);
	this->GetInfoFrame(pathfile, 11);

}
bool Sprite::Load(const char* imagepath)
{
	path = imagepath;
	texture = IMG_LoadTexture(Renderer::GetInstance()->Getrenderer(), imagepath);
	if (texture == NULL)
	{
		SDL_Log("Load image failed. Error: %s", IMG_GetError());
		return false;
	}
	return true;
}
void Sprite::ReadFile(const char* FilePath, char * &buff, int &fileSize)
{
	FILE *pFile = fopen(FilePath, "rb");
	if (pFile == NULL)
	{
		printf("NOT READ \n");
		return;
	}

	fseek(pFile, 0, SEEK_END);
	fileSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);

	if (buff != NULL)
	{
		delete[] buff;
	}

	buff = new char[fileSize];
	fread(buff, 1, fileSize, pFile);
	fclose(pFile);

}
void Sprite::GetInfoFrame(const char* path, int sumFrame)
{
	char* buff = nullptr;
	int Size = 0;
	ReadFile(path, buff, Size);
	//printf("\n%d SIZE\n", Size);
	int ID = 0;
	for (int i = 4; i < Size; i++)
	{
			if (ID <=sumFrame && (buff[i] > 47 && buff[i] < 58))
			{
				char Result[4][4];
				for (int j = 0; j < 4; j++)
				{
					int Lenght = 0;
					for (int k = i; k < i + 4; k++, i++)
					{
						if (buff[k] < 48 || buff[k] > 57)
						{
							Result[j][Lenght] = '\0';
							i++;
							break;
						}
						else
						{
							Result[j][Lenght] = buff[k];
							Lenght++;
						}
					}
				}
				SDL_Rect SpriteSize;
				SpriteSize.x = atoi(Result[0]);
				SpriteSize.y = atoi(Result[1]);
				SpriteSize.w = atoi(Result[2]);
				SpriteSize.h = atoi(Result[3]);
				listFrame.push_back(SpriteSize);

			}
			else if (buff[i] == '\n')
			{
				ID++;
			}
	}
}


SDL_Texture* Sprite::GetTexture()
{
	return texture;
}



Sprite::Sprite()
{
	//path = "spr_data.cnf";
}

Sprite::~Sprite()
{
}