#include "ScoreBehavior.h"
#include "../Components/Transform2d.h"
#include "../Behavior/BricksBehavior.h"
#include "../Behavior/PlayerBehavior.h"
#include"../Behavior/BallBehavior.h"

#include <iostream>

void ScoreBehavior::Awake()
{
	Add<TextRender>();
	m_score = 0;
	m_size = 30;
	m_color = sf::Color::White;
}

void ScoreBehavior::Start()
{
	if (!m_font.loadFromFile("../../../res/font.ttf"))
	{
		std::cout << "Erreur : Impossible de charger la police " << std::endl;
	}
}

void ScoreBehavior::Update(float _delta_time)
{
	Scene* scene = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene();

	if (m_score >= 150)
	{
		m_string = "Vous avez gagné !";
		std::vector<BallBehavior*> balls = scene->GetAll<BallBehavior>();
		std::vector<BricksBehavior*> bricks = scene->GetAll<BricksBehavior>();
		std::vector<PlayerBehavior*> player = scene->GetAll<PlayerBehavior>();
		for (PlayerBehavior* p : player) { scene->DestroyEntity(p->GetID()); }
		for (BricksBehavior* brick : bricks) { scene->DestroyEntity(brick->GetID()); }
		for (BallBehavior* ball : balls){scene->DestroyEntity(ball->GetID());}
	}
	else { m_string = "Score : " + std::to_string(m_score); }

	Get<TextRender>()->SetText (m_font, m_string, m_size, m_color);
}

void ScoreBehavior::IncreaseScore(int score)
{
	m_score += score;
}