#include "ProjectilBehavior.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../Components/Transform2d.h"
#include "../Components/Sound.h"
#include <iostream>

void ProjectilBehavior::Awake()
{
	Add<Sound>();
	Add<Collider>();
	Add<SpriteRender>();
	Get<SpriteRender>()->SetTexture("../../../res/Projectil.png");
	Get<Transform2d>()->scale(0.5, 0.5);
}

void ProjectilBehavior::Start()
{

}

void ProjectilBehavior::SetDirection(sf::Vector2f _direction)
{
	m_direction = _direction;
}

void ProjectilBehavior::Update(float _delta_time)
{
	Get<Transform2d>()->move(m_direction * _delta_time);
	if (!(Get<Transform2d>()->getPosition().x >= 0 && Get<Transform2d>()->getPosition().x <= 800 && Get<Transform2d>()->getPosition().y >= 0 && Get<Transform2d>()->getPosition().y <= 600))
	{
		Scene* scene = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene();
		scene->DestroyEntity(GetID());
		std::cout << "Destroyed" << std::endl;
	}
}
