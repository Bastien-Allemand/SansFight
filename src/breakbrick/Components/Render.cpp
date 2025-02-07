#include "Render.h"
#include <SFML/Graphics.hpp>
#include "Transform2d.h"
#include <iostream>

void Render::Awake(){}
void Render::Start(){}

void Render::draw(sf::RenderTarget& _target, sf::RenderStates _states) const{
	_states.transform.combine(Get<Transform2d>()->getTransform());
	_target.draw(*m_drawable, _states);

}

