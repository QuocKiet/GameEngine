#include "EventManager.h"
#include "Application.h"
#include "SceneManager.h"
#include "../../Src/Game/PauseScene.h"
EventManager* EventManager:: Instance = NULL;

EventManager* EventManager::GetInstance()
{
	if (Instance == NULL)
	{
		Instance = new EventManager();
	}
	return Instance;
}
//Status EventManager::Getstatus()
//{
//	return status;
//}

SDL_Point EventManager::GetMousePos()
{
	return mousePosition;
}

bool EventManager::GetMouseState(int a)
{
	return mouseState[a-1];
}

bool EventManager::IsKeyDown(int key)
{
	return keyState[key];
}

bool EventManager::IsKeyUp(int key)
{
	return keyState[key];
}

bool EventManager::IsMouseButtonDown(int mouseButton)
{
	return mouseState[mouseButton - 1];
}

bool EventManager::IsMouseButtonUp(int mouseButton)
{
	return mouseState[mouseButton - 1];
}

void EventManager::ProcessEvent()
{
	SDL_Event mainEvent;
	while (SDL_PollEvent(&mainEvent))
	{
		switch (mainEvent.type)
		{
		case SDL_QUIT:
		{
			Application::GetInstance()->SetIsRunning(false);
			break;
		}

		//Mouse button pressed
		case SDL_MOUSEBUTTONDOWN:
		{
			//mouseState[mainEvent.button.button - 1] = true;
			/*for (std::vector<GameObject*>::iterator i= Application::GetInstance()->GetScene()->GetListGameObject().begin();i < Application::GetInstance()->GetScene()->GetListGameObject().end();i++)
			{
				Button* button = dynamic_cast <Button*>(*i);
				if (button != NULL)
				{
					if(mousePosition.x >= )
				}
			}*/
			vector<GameObject*> n = SceneManager::GetInstane()->GetCurrenScene()->GetListGameObject();
			for (int i = 0; i < n.size(); i++)
			{
				if (n[i]->GetTypeObject() == "Button")
				{
					if (n[i]->GetIsClick() == false)
					{
						if (mousePosition.x >= (n[i]->GetPos().x) &&
							mousePosition.x <= (n[i]->GetPos().x + n[i]->GetWidth()) &&
							mousePosition.y >= (n[i]->GetPos().y) &&
							mousePosition.y <= (n[i]->GetPos().y + n[i]->GetHeight())
							)
						{
							n[i]->SetIsClick(true);
						}
					}
					else
					{
						if (mousePosition.x >= (n[i]->GetPos().x) &&
							mousePosition.x <= (n[i]->GetPos().x + n[i]->GetWidth()) &&
							mousePosition.y >= (n[i]->GetPos().y) &&
							mousePosition.y <= (n[i]->GetPos().y + n[i]->GetHeight())
							)
						{
							n[i]->SetIsClick(false);
						}
					}
					
				}
			}
			break;
		}

		//Mouse button released
		case SDL_MOUSEBUTTONUP:
		{
			mouseState[mainEvent.button.button - 1] = false;
			//vector<GameObject*> n = SceneManager::GetInstane()->GetCurrenScene()->GetListGameObject();
			//for (int i = 0; i < n.size(); i++)
			//{
			//	if (n[i]->GetTypeObject() == "Button")
			//	{
			//		/*if (mousePosition.x >= (n[i]->GetPos().x) &&
			//			mousePosition.x <= (n[i]->GetPos().x + n[i]->GetWidth()) &&
			//			mousePosition.y >= (n[i]->GetPos().y) &&
			//			mousePosition.y <= (n[i]->GetPos().y + n[i]->GetHeight())
			//			)*/
			//		{
			//			n[i]->SetIsClick(false);
			//		}
			//	}
			//}

			break;
		}

		//Mouse moved
		case SDL_MOUSEMOTION:
		{
			mousePosition.x = mainEvent.motion.x;
			mousePosition.y = mainEvent.motion.y;
			break;
		}

		//Mouse wheel motion
		case SDL_MOUSEWHEEL:
		{
			printf("Mouse Wheel Motion\n");
			break;
		}

		//Key pressed
		case SDL_KEYDOWN:
		{
			//printf("%d\n", mainEvent.key.keysym.sym);
			keyState[mainEvent.key.keysym.sym] = true;
			/*
			
			/*if (mainEvent.key.keysym.sym == 119)
			{
				Resource::GetInstance()->gamePlayScene->GetPlayer()->SetPos(1, Resource::GetInstance()->gamePlayScene->GetPlayer()->GetPos().y - 2);
			}
			if (mainEvent.key.keysym.sym == 115)
			{
				Resource::GetInstance()->gamePlayScene->GetPlayer()->SetPos(1, Resource::GetInstance()->gamePlayScene->GetPlayer()->GetPos().y + 2);
			}*/
			break;
		}

		//Key released
		case SDL_KEYUP:
		{
			keyState[mainEvent.key.keysym.sym] = false;
			break;
		}
		default:
			break;
		}
	}

}

EventManager::EventManager()
{
	for (int i = 0; i < 3; i++)
	{
		mouseState[i] = false;
	}
}

EventManager::~EventManager()
{
}

