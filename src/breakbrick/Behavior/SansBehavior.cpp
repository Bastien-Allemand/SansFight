#include "SansBehavior.h"
#include <iostream>
#include "../Components/Transform2d.h"
#include "../Components/Collider.h"
#include "../Behavior/HeartBehavior.h"
#include "../Components/SpriteRender.h"
#include "../Behavior/ProjectilBehavior.h"
#include "../Components/Sound.h"

void SansBehavior::Awake()
{
	Add<SpriteRender>();
	Add<Sound>();
}

void SansBehavior::Start()
{
	Get<SpriteRender>()->SetTexture("../../../res/SansAttackSpritesheet.png", sf::IntRect(190, 130, 115, 204));
	Get<Transform2d>()->setPosition(341.5, 110);
}

void SansBehavior::Update(float _delta_time)
{

	m_timer += _delta_time;
	if (m_timer >= 2)
	{
		switch (m_current_frame)
		{
		case 0:
			Get<SpriteRender>()->SetTexture("../../../res/SansAttackSpritesheet.png", sf::IntRect(190, 130, 115, 204));
			m_current_frame++;
			m_timer = 1.85f;
			break;
		case 1:
			Get<SpriteRender>()->SetTexture("../../../res/SansAttackSpritesheet.png", sf::IntRect(310, 130, 177, 204));
			m_current_frame++;
			m_timer = 1.85f;
			break;
		case 2:
			Get<SpriteRender>()->SetTexture("../../../res/SansAttackSpritesheet.png", sf::IntRect(500, 130, 177, 204));
			m_current_frame++;
			m_timer = 1.85f;
			Get<Sound>()->addSound("../../../res/KetchupBlast.mp3");
			Get<Sound>()->getsound(0)->setVolume(10);
			Get<Sound>()->getsound(0)->play();
			break;
		case 3:
			Get<SpriteRender>()->SetTexture("../../../res/SansAttackSpritesheet.png", sf::IntRect(190, 130, 115, 204));
			m_current_frame = 0;
			m_timer = 0;
			break;
		}
		
	}
}
