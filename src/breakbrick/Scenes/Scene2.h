#pragma once
#include "../Abstract/Scene.h"
#include <SFML/Audio.hpp>

class Scene2 : public Scene
{
	float m_timer;
	sf::Music m_music;
public:
	Scene2();
	~Scene2();
	void Init() override;
	void Update(float _delta_time) override;
};

