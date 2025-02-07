#pragma once
#include "../Abstract/Component.h"
#include <SFML/Audio.hpp>
#include <string>
class Sound : public Component
{
	std::vector<sf::SoundBuffer*> m_buffer;
	std::vector<sf::Sound*> m_sound;
public:
	Sound();
	~Sound();
	void Awake();
	void Start();

	void addSound(std::string _path);
	sf::Sound* getsound(int _index);
};

