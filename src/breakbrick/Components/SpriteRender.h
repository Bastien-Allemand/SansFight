#pragma once
#include "Render.h"

class SpriteRender : public Render
{
	sf::Sprite m_sprite;
	sf::Texture m_texture;
public:

	SpriteRender();
	virtual void SetTexture(std::string _path);
	virtual void SetTexture(std::string _path, sf::IntRect _rect);
	virtual void SetTexture(sf::Texture* _texture);
	sf::Sprite* GetSprite();
	sf::Texture* GetTexture();
	void Awake() override;
	void Start() override;


};

