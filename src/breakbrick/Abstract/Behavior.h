#pragma once
#include "Component.h"
class Behavior : public Component
{

public:
	virtual void Awake() = 0;
	virtual void Start() = 0;
	virtual void Update(float _delta_time) = 0;
};

