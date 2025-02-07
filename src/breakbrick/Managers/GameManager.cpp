#include "GameManager.h"

class Transform2d;
class Collider;
class SpriteRender;
class PlayerBehavior;

GameManager* GameManager::m_instance = nullptr;

GameManager* GameManager::GetInstance(){
    if (!m_instance)    {
        m_instance = new GameManager();
    }
    return m_instance;
}


sf::RenderWindow* GameManager::GetWindow(){return &m_window;}

SceneManager* GameManager::GetSceneManager(){return m_scene_manager;}

void GameManager::Run(){
	m_window.create(sf::VideoMode(800, 600), "EnETRE");
	sf::Clock clock;

	m_scene_manager = new SceneManager();
	m_scene_manager->Init();
	m_scene_manager->GetCurrentScene()->Start();

	while (m_window.isOpen()){
		sf::Time elapsed = clock.restart();
		float delta_time = elapsed.asSeconds();

		sf::Event event;
		while (m_window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		m_scene_manager->GetCurrentScene()->Physics();
		m_scene_manager->GetCurrentScene()->Update(delta_time);
		m_window.clear(sf::Color::Black);
		m_window.draw(*m_scene_manager->GetCurrentScene());
		m_window.display();

		m_scene_manager->ChangeScene();
	}
}
