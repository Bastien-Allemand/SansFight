#pragma once
#include "../Abstract/Behavior.h"

class SansBehavior : public Behavior
{
	float m_timer;
	int m_current_frame;
public:
	void Awake() override;

	void Start() override;

	void Update(float _delta_time) override;
};

