#pragma once
#include "../Abstract/Behavior.h"
#include "../Abstract/iCollider.h"

class PlayerBehavior : public Behavior
{
public:
	void Update(float _delta_time) override;

	void Awake() override;

	void Start() override;
};

