#include "main.h"
#include "SFML/Graphics.hpp"
#include "Managers/GameManager.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));
	GameManager* game_manager = GameManager::GetInstance();
	game_manager->Run();

	return 0;
}
