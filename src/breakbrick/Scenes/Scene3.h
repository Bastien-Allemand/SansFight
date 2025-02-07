#pragma once
#include "../Abstract/Scene.h"

class Scene3 : public Scene
{
public:
	Scene3();
	virtual void Init() override;
	virtual void Update(float _delta_time) override;
};

