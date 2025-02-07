#pragma once
#include "SceneManager.h"
class GameManager
{
	static GameManager* m_instance;
	sf::RenderWindow m_window;
	Scene* m_current_scene;
	SceneManager* m_scene_manager;
	

public:

	static GameManager* GetInstance();
	sf::RenderWindow* GetWindow();
	SceneManager* GetSceneManager();
	void Run();

};

