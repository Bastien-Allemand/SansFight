#pragma once
#include "../Abstract/Behavior.h"
#include "../Abstract/iCollider.h"

class ProjectilBehavior : public Behavior
{
	sf::Vector2f m_direction;

public:

	void Awake() override;

	void Start() override;

	void SetDirection(sf::Vector2f _direction);

	virtual void Update(float _delta_time);
};

