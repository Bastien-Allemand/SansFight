#pragma once
#include "../Abstract/Component.h"

class Transform2d : public Component, public sf::Transformable
{
public:
	void Awake() override;

	void Start() override;

};

