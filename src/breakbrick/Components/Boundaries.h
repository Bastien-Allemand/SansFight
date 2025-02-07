#pragma once
#include "../Abstract/Component.h"

class Boundaries : public Component
{
	sf::FloatRect m_bounds;
public:
	void Awake() override;

	void Start() override;

	void SetBounds(sf::FloatRect _bounds);

	bool CheckBoundsX();

	bool CheckBoundsY();

	bool CheckBoundsXRect();

	bool CheckBoundsYRect();
};

