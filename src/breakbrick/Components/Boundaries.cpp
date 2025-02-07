#include "Boundaries.h"
#include "Transform2d.h"
#include "SpriteRender.h"

void Boundaries::Awake(){}

void Boundaries::Start(){}

void Boundaries::SetBounds(sf::FloatRect _bounds){m_bounds = _bounds;}

bool Boundaries::CheckBoundsX(){
	bool out = false;
	if (Get<Transform2d>()->getPosition().x <= m_bounds.getPosition().x){
		out = true;
	}
	return out;
}

bool Boundaries::CheckBoundsY(){
	bool out = false;
	if (Get<Transform2d>()->getPosition().y <= m_bounds.getPosition().y){
		out = true;
	}
	return out;
}

bool Boundaries::CheckBoundsXRect(){
	bool out = false;
	if (Get<Transform2d>()->getPosition().x + Get<SpriteRender>()->GetSprite()->getScale().x >= m_bounds.getPosition().x + m_bounds.getSize().x){
		out = true;
	}
	return out;
}

bool Boundaries::CheckBoundsYRect(){
	bool out = false;
	if (Get<Transform2d>()->getPosition().y + Get<Transform2d>()->getScale().y >= m_bounds.getPosition().y + m_bounds.getSize().y){
		out = true;
	}
	return out;
}
