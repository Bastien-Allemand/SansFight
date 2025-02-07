#pragma once
#include "../Scenes/Scene1.h"
#include <vector>

class SceneManager
{
	std::vector<Scene*> m_scenes;
	Scene* m_currentScene;
	Scene* m_nextScene;

public:
	SceneManager();
	~SceneManager();

	void Init();
	virtual void RemoveScene(Scene* _scene);
	virtual void RemoveScene(int _scene_number);

	template<class T>
	std::vector<T*> GetAllScenes();
	template<class T>
	T GetScene();

	Scene* GetCurrentScene();
	void SetCurrentScene(Scene* _scene);
	void SetNextScene(Scene* _scene);
	void AddScene(Scene* _scene);
	void ChangeScene();
};

template<class T>
inline std::vector<T*> SceneManager::GetAllScenes()
{
	std::vector<T*> scenes;
	for (Scene* scene : m_scenes)
	{
		if (T* s = dynamic_cast<T*>(scene))
		{
			scenes.push_back(s);
		}
	}
	return scenes;
}

template<class T>
inline T SceneManager::GetScene()
{
	for (Scene* scene : m_scenes)
	{
		if (T* s = dynamic_cast<T*>(scene))
		{
			return s;
		}
	}

	return nullptr;
}