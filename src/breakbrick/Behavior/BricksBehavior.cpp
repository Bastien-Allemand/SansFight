#include "BricksBehavior.h"
#include "../Components/SpriteRender.h"
#include "../Components/Collider.h"
#include "../Components/Transform2d.h"
#include "ScoreBehavior.h"

void BricksBehavior::Update(float _delta_time)
{
}

void BricksBehavior::OnCollide(Collider* _colliding)
{
	Scene* scene = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene();
	ScoreBehavior* scoreBehavior = scene->GetAll<ScoreBehavior>()[0];

	scoreBehavior->IncreaseScore(10);
	scene->DestroyEntity(GetID());

}

void BricksBehavior::Awake()	
{
	Add<Collider>();
	Add<SpriteRender>();

}

void BricksBehavior::Start()
{
	Get<Transform2d>()->scale(0.2, 0.1);

}

