#pragma once
#include "../Components/Collider.h"

class iCollider
{
public:
	virtual void OnCollide(Collider* _colliding) = 0;

};

