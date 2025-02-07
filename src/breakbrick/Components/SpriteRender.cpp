#include "SpriteRender.h"

SpriteRender::SpriteRender(){}

void SpriteRender::SetTexture(std::string _path){
	m_texture.loadFromFile(_path);
	m_sprite.setTexture(m_texture);
}

void SpriteRender::SetTexture(std::string _path, sf::IntRect _rect){
	m_texture.loadFromFile(_path, _rect);

	m_sprite.setTexture(m_texture,true);
}

void SpriteRender::SetTexture(sf::Texture* _texture){
	m_texture = *_texture;
	m_sprite.setTexture(m_texture);
}

sf::Sprite* SpriteRender::GetSprite(){
	return &m_sprite;
}

sf::Texture* SpriteRender::GetTexture(){
	return &m_texture;
}

void SpriteRender::Awake(){
	m_drawable = &m_sprite;
}

void SpriteRender::Start(){}
