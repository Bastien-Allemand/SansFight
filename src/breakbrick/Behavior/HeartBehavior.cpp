#include "HeartBehavior.h"
#include "../Components/Collider.h"
#include "../Components/Boundaries.h"
#include "../Components/SpriteRender.h"
#include "../Components/Transform2d.h"
#include "../Components/Sound.h"
#include "../Scenes/Scene3.h"

void HeartBehavior::Update(float _delta_time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!Get<Boundaries>()->CheckBoundsXRect())
		{
			Get<Transform2d>()->move(120.f * _delta_time, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (!Get<Boundaries>()->CheckBoundsX())
		{
			Get<Transform2d>()->move(-120.f * _delta_time, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!Get<Boundaries>()->CheckBoundsY())
		{
			Get<Transform2d>()->move(0, -120.f * _delta_time);
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (!Get<Boundaries>()->CheckBoundsYRect())
		{
			Get<Transform2d>()->move(0, 120.f * _delta_time);
		}
	}
}

void HeartBehavior::OnCollide(Collider* _colliding)
{
	Get<Sound>()->addSound("../../../res/Death(2).mp3");
	SceneManager* scene_manager = GameManager::GetInstance()->GetSceneManager();
	scene_manager->GetCurrentScene()->GetAll<Sound>()[0]->getsound(0);
	scene_manager->SetNextScene(new Scene3());
}

void HeartBehavior::Awake()
{
	
}

void HeartBehavior::Start()
{
	Add<Collider>();
	Add<Boundaries>();
	Add<SpriteRender>();
	Add<Sound>();

	Get<Boundaries>()->SetBounds(sf::FloatRect(238, 310, 295, 175));
	Get<SpriteRender>()->SetTexture("../../../res/heart.png");

	Get<Transform2d>()->scale(0.17, 0.17);
	Get<Transform2d>()->setPosition(400, 450);
}