#pragma once
#include "../Abstract/Component.h"

class Collider :public Component
{
public:
	bool CheckCollide(Collider* _collider);

	void CollisionEnter(Collider* _collider);

	void CollisionStay(Collider* _collider);

	void CollisionEnd(Collider* _collider);

	void Awake() override;

	void Start() override;
};

