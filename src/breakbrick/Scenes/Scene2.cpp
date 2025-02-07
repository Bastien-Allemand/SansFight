#include "Scene2.h"
#include <iostream>
#include "../Components/Transform2d.h"
#include "../Behavior/SansBehavior.h"
#include "../Components/Collider.h"
#include "../Behavior/HeartBehavior.h"
#include "../Components/SpriteRender.h"
#include "../Behavior/ProjectilBehavior.h"
#include "../Components/Sound.h"

Scene2::Scene2() : Scene(){}

Scene2::~Scene2(){m_music.stop();}

void Scene2::Init(){
	m_music.openFromFile("../../../res/Music.mp3");
	m_music.setVolume(30);
	m_music.setLoop(true);
	m_music.play();


	Component* heart = CreateEntity();
	heart->Add<HeartBehavior>();

	Component* Rectangle = CreateEntity();
	Rectangle->Add<SpriteRender>();
	Rectangle->Get<SpriteRender>()->SetTexture("../../../res/Rectangle.png");
	Rectangle->Get<Transform2d>()->setPosition(230,310);

	Component* m_sans = CreateEntity();
	m_sans->Add<SansBehavior>();
	
}

void Scene2::Update(float _delta_time){
	m_timer += _delta_time;
	if (m_timer >= 2.45f)
	{
		Component* projectil = CreateEntity();

		SceneManager* scene_manager = GameManager::GetInstance()->GetSceneManager();
		Component* heart_ = scene_manager->GetCurrentScene()->GetAll<HeartBehavior>()[0];

		projectil->Add<ProjectilBehavior>();
		projectil->Get<Transform2d>()->setPosition(rand() % 700, rand() % 500);

		sf::Vector2f projectil_position = projectil->Get<Transform2d>()->getPosition();
		sf::Vector2f heart_position = heart_->Get<Transform2d>()->getPosition();

		if (projectil_position.x < heart_position.x - 100 && projectil_position.x >= heart_position.x + 100)
		{projectil->Get<Transform2d>()->setPosition(200 + projectil_position.x,projectil_position.y);}

		if (projectil_position.y < heart_position.y - 100 && projectil_position.y >= heart_position.y + 100)
		{projectil->Get<Transform2d>()->setPosition(projectil_position.x, 200 + projectil_position.y);}

		projectil->Get<ProjectilBehavior>()->SetDirection(heart_position - projectil_position);
		m_timer = 0;
	}
	Scene::Update(_delta_time);
}
