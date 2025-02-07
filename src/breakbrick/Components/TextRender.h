#pragma once
#include <string>
#include "Render.h"

class TextRender : public Render
{
	sf::Text m_text;
public:
	sf::Text& GetText();

	void Awake() override;

	void Start() override;

	void SetText(sf::Font& _font, sf::String _string, int _size, sf::Color _color);

};
