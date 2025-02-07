#include "TextRender.h"

void TextRender::Awake(){m_drawable = &m_text;}

void TextRender::Start(){}

void TextRender::SetText(sf::Font& font, sf::String string, int size, sf::Color color){
	m_text.setFont(font);
	m_text.setString(string);
	m_text.setCharacterSize(size);
	m_text.setFillColor(color);
}


sf::Text& TextRender::GetText(){return m_text;}
