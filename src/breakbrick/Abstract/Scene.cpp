#include "Scene.h"

#include "../Components/Transform2d.h"
#include "../Components/Collider.h"
#include "../Behavior/BallBehavior.h"
#include "../Behavior/BricksBehavior.h"
#include "../Behavior/PlayerBehavior.h"
#include "../Components/SpriteRender.h"
#include "../Components/Sound.h"
#include <iostream>


Scene::~Scene()
{
	for (Component* c : m_components)
	{
		std::cout << m_components.size() << " : Size" << std::endl;
		std::cout << c->GetID()<< " :IDOFDELETE" << std::endl;
		delete c;

	}
	m_components.clear();
}

Component* Scene::CreateEntity()
{
	Component* entity = new Transform2d();
	m_components.push_back(entity);
	entity->Awake();
	entity->SetID(next_entity_ID);
	next_entity_ID++;
	std::cout << entity->GetID() << ": ID" << std::endl;
	return entity;
}

void Scene::DestroyEntity(int _entity_id)
{
	for (auto it = m_components.begin(); it != m_components.end(); ++it)
	{
		if ((*it)->GetID() == _entity_id)
		{
			(*it)->destroy = true;
		}
	}
}

void Scene::AddComponent(Component* _component)
{
	m_components.push_back(_component);
}

void Scene::Start()
{
	for (int i = 0; i < m_components.size(); i++)
	{
		m_components[i]->Start();
	}
}



void Scene:: Update(float _delta_time)
{
	std::vector <Behavior*> b = GetAll<Behavior>();
	for (Behavior* tb : b) 
	{
		tb->Update(_delta_time);
	}

	for (auto it = m_components.begin(); it != m_components.end();) {
		if ((*it)->destroy) {
			delete* it;
			it = m_components.erase(it);
		}
		else {
			++it;
		}
	}
}
void Scene::Physics()
{
	std::vector<Collider*> colliders = GetAll<Collider>();

	std::pair<Collider*,Collider*> m_collider_frame;
	for (int i = 0; i < colliders.size(); i++)
	{
		for (int j = 0; j < colliders.size(); j++)
		{
			if (colliders[i] != colliders[j]) 
			{
				m_collider_frame = std::pair<Collider*, Collider*>(colliders[i], colliders[j]);
				std::pair<Collider*, Collider*> reverse = std::pair<Collider*, Collider*>(colliders[j], colliders[i]);
				if (std::find(m_collider.begin(), m_collider.end(), reverse) == m_collider.end() && colliders[i]->destroy == false && colliders[j]->destroy == false && colliders[i]->CheckCollide(colliders[j]))
				{
					if (std::find(m_collider.begin(),m_collider.end(), m_collider_frame) != m_collider.end())
					{
						colliders[i]->CollisionStay(colliders[j]);
					}
					else
					{
						colliders[i]->CollisionEnter(colliders[j]);
						m_collider.push_back(m_collider_frame);
					}

					if (m_collider.size() == 0)
					{
						m_collider.push_back(m_collider_frame);
						colliders[i]->CollisionEnter(colliders[j]);

					}
				}
				else
				{
					for (auto it = m_collider.begin(); it != m_collider.end();)
					{
						if ((*it) == m_collider_frame)
						{
							colliders[i]->CollisionEnd(colliders[j]);
							it = m_collider.erase(it);
						}
						else
						{
							++it;
						}

					}
				}
			}
		}
	}
}

void Scene::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{	
	std::vector <Render*> r = GetAll<Render>();
	for (Render* tb : r) 
	{
		_target.draw(*tb, _states);
	}
}
