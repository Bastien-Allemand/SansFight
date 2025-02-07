#pragma once
#include "../Abstract/Behavior.h"
#include "../Components/TextRender.h"
#include <string>

class ScoreBehavior : public Behavior
{
	int m_score;
	int m_size;

	std::string m_string;

	sf::Color m_color;
	sf::Font m_font;
public:
	void IncreaseScore(int score);

	void Update(float _delta_time) override;

	void Awake() override;

	void Start() override;
};

