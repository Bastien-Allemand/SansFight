#pragma once
#include "../Abstract/Behavior.h"
#include "../Abstract/iCollider.h"

class HeartBehavior : public Behavior, public iCollider
{
public:
	void Update(float _delta_time) override;

	void OnCollide(Collider* _colliding) override;

	void Awake() override;

	void Start() override;
};

