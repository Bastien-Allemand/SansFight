#pragma once
#include <SFML/Graphics.hpp>
class Component;
class Collider;


class Scene : public sf::Drawable
{
	int next_entity_ID = 0;
	std::vector<Component*> m_components;
	std::vector<std::pair<Collider*,Collider*>> m_collider;

public:
	~Scene();
	Component* CreateEntity();
	template<typename T>
	std::vector<T*> GetAll() const;
	void DestroyEntity(int _entity_id);
	void AddComponent(Component* _component);

	void Start();
	virtual void Init() = 0;
	virtual void Physics();
	virtual void Update(float _delta_time);
	void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;

};


template<typename T>
inline std::vector<T*> Scene::GetAll() const
{
	std::vector<T*> temp;
	for (int i = 0; i < m_components.size(); i++)
	{
		if (T* t = dynamic_cast<T*>(m_components[i]))
			temp.push_back(t);

	}
	return temp;

}

