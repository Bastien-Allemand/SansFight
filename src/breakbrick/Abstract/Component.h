#pragma once
#include "../Managers/GameManager.h"

class Scene;

class Component
{
protected:
	int m_id;
public:
	~Component() = default;
	int GetID() const;
	void SetID(int _id);
	virtual void Awake() = 0;
	virtual void Start() = 0;

	template <typename T>
	T* Get() const;
	template <typename T>
	T* Add();
	template <typename T>
	std::vector<T*> GetAll() const;
	bool destroy = false;
};


template<typename T>
inline T* Component::Get() const
{
	Scene* scene = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene();
	if (scene)
	{
		std::vector<T*> components = scene->GetAll<T>();
		for (int i = 0; i < components.size(); i++)
		{
			if (T* t = dynamic_cast<T*>(components[i]))
			{
				if (t->GetID() == this->GetID())
				{
					return (t);
				}
			}
		}
		return nullptr;
	}
}

template<typename T>
inline T* Component::Add()
{
	Scene* scene = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene();
	if (scene)
	{
		T* t = new T();
		t->m_id = m_id;
		scene->AddComponent(t);
		t->Awake();
		return t;
	}
	return nullptr;
}

template<typename T>
inline std::vector<T*> Component::GetAll() const
{
	std::vector<T*> temp;

	Scene* scene = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene();
	if (scene)
	{
		std::vector<T*> components_id = scene->GetAll<T>();

		for (int i = 0; i < components_id.size(); i++)
		{
			if (T* t = dynamic_cast<T*>(components_id[i])) {
				if (t->GetID() == this->GetID())
				{
					temp.push_back(t);
				}
			}

		}

	}
	return temp;
}
