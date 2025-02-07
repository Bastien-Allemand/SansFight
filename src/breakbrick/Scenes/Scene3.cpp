#include "Scene3.h"
#include "Scene2.h"

#include "../Components/Transform2d.h"
#include "../Behavior/SansBehavior.h"
#include "../Components/Collider.h"
#include "../Behavior/HeartBehavior.h"
#include "../Components/SpriteRender.h"
#include "../Behavior/ProjectilBehavior.h"

#include <iostream>

Scene3::Scene3() : Scene(){}

void Scene3::Init(){
	Component* game_over = CreateEntity();
	game_over->Add<SpriteRender>();
	game_over->Get<SpriteRender>()->SetTexture("../../../res/GameOver2.png");
	game_over->Get<Transform2d>()->setPosition(0, 100);
}

void Scene3::Update(float _delta_time){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		GameManager::GetInstance()->GetWindow()->close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
		SceneManager* scene_manager = GameManager::GetInstance()->GetSceneManager();
		scene_manager->SetNextScene(new Scene2());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		SceneManager* scene_manager = GameManager::GetInstance()->GetSceneManager();
		scene_manager->SetNextScene(new Scene1());
	}
	Scene::Update(_delta_time);
}
