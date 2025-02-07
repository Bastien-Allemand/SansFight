#pragma once
#include "../Abstract/Behavior.h"
#include "../Abstract/iCollider.h"
class BallBehavior : public Behavior , public iCollider
{
	sf::Vector2f m_velocity;

public:
	void Update(float _delta_time) override;

	void Awake() override;

	void Start() override;

	void OnCollide(Collider* _colliding) override;


};

