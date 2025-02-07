#include "BallBehavior.h"
#include "../Components/SpriteRender.h"
#include "../Components/Collider.h"
#include "../Components/Transform2d.h"
#include "../Scenes/Scene3.h"
#include <iostream>

void BallBehavior::Update(float _delta_time)
{
	Transform2d* transform = Get<Transform2d>();
	sf::Vector2f position = transform->getPosition();

	Scene* scene = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene();

	if (position.y > 625)
	{ 
		std::cout << "Ball détruite" << std::endl;
		SceneManager* scene_manager = GameManager::GetInstance()->GetSceneManager();
		scene_manager->SetNextScene(new Scene3());
	}

	transform->setPosition(position.x + m_velocity.x * _delta_time, position.y + m_velocity.y * _delta_time);
}

void BallBehavior::Awake()
{
	Add<Collider>();
	Add<SpriteRender>()->GetSprite()->setScale(0.25, 0.25);


	m_velocity = sf::Vector2f(-200.0f, 200.0f);
}

void BallBehavior::Start()
{
	SpriteRender* sr = Get<SpriteRender>();
	sr->SetTexture("../../../res/BALLER.png");
	Get<Transform2d>()->scale(0.02, 0.02);


}

void BallBehavior::OnCollide(Collider* _colliding)
{
	Transform2d* ball_transform2d = Get<Transform2d>();
	Transform2d* colliding_transform2d = _colliding->Get<Transform2d>();

	SpriteRender* ball_sprite_render = Get<SpriteRender>();
	SpriteRender* colliding_sprite_render = _colliding->Get<SpriteRender>();

	sf::Vector2f ball_current_position = ball_transform2d->getPosition();
	sf::Vector2f colliding_current_position = colliding_transform2d->getPosition();

	sf::FloatRect ball_bounds = ball_sprite_render->GetSprite()->getGlobalBounds();
	ball_bounds = ball_transform2d->getTransform().transformRect(ball_bounds);

	sf::FloatRect colliding_bounds = colliding_sprite_render->GetSprite()->getGlobalBounds();
	colliding_bounds = colliding_transform2d->getTransform().transformRect(colliding_bounds);

	sf::Vector2f ballCenter = ball_current_position + sf::Vector2f(ball_bounds.width / 2, ball_bounds.height / 2);


	if ((ballCenter.x <= colliding_current_position.x && ballCenter.y >= colliding_current_position.y && ballCenter.y <= colliding_current_position.y + colliding_bounds.height)
		|| (ballCenter.x >= colliding_current_position.x + colliding_bounds.width && ballCenter.y >= colliding_current_position.y && ballCenter.y <= colliding_current_position.y + colliding_bounds.height)) {
		m_velocity.x *= -1;
	}

	else if ((ballCenter.y <= colliding_current_position.y && ballCenter.x >= colliding_current_position.x && ballCenter.x <= colliding_current_position.x + colliding_bounds.width)
		|| (ballCenter.y >= colliding_current_position.y + colliding_bounds.height && ballCenter.x >= colliding_current_position.x && ballCenter.x <= colliding_current_position.x + colliding_bounds.width)) {
		m_velocity.y *= -1;
	}
	else {
		m_velocity.y *= -1;
		m_velocity.x *= -1;
	}

}
