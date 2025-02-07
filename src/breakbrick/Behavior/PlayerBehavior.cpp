#include "PlayerBehavior.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../Components/Transform2d.h"
#include "../Components/Boundaries.h"

#include <iostream>


void PlayerBehavior::Update(float _delta_time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!Get<Boundaries>()->CheckBoundsXRect())
		{
			Get<Transform2d>()->move(200.f * _delta_time, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		if (!Get<Boundaries>()->CheckBoundsX())
		{
			Get<Transform2d>()->move(-200.f * _delta_time, 0);
		}
	}
}

void PlayerBehavior::Awake()
{
	

	Add<Collider>();
	Add<Boundaries>();
	Add<SpriteRender>();


}

void PlayerBehavior::Start()
{
	float window_width = GameManager::GetInstance()->GetWindow()->getSize().x;
	Get<SpriteRender>()->SetTexture("../../../res/PongPADDLE.png");
	Get<Boundaries>()->SetBounds(sf::FloatRect(0, 0, window_width - 105, 600));
}


