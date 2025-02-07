#include "Sound.h"
#include <iostream>
Sound::Sound(){}

Sound::~Sound(){
	for (int i = 0; i < m_sound.size(); i++){
		m_sound[i]->stop();
		delete m_buffer[i];
		delete m_sound[i];
	}
}

void Sound::Awake(){}
void Sound::Start(){}

void Sound::addSound(std::string _path){
	sf::SoundBuffer* buffers = new sf::SoundBuffer();
	buffers->loadFromFile(_path);

	m_buffer.push_back(buffers);

	sf::Sound* sounds = new sf::Sound();
	sounds->setBuffer(*buffers);

	m_sound.push_back(sounds);
}

sf::Sound* Sound::getsound(int _index){
	m_sound[_index]->stop();

	return m_sound[_index];
}
