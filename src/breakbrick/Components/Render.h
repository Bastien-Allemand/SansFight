#pragma once
#include "../Abstract/Component.h"


class Render : public Component, public sf::Drawable
{
protected:
	sf::Drawable* m_drawable;
public:
	virtual void Awake() override;

	virtual void Start() override;

	virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;

};

