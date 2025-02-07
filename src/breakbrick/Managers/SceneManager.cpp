#include "SceneManager.h"
#include "../Scenes/Scene2.h"
#include "../Scenes/Scene3.h"

 SceneManager::SceneManager(){}


SceneManager::~SceneManager(){
	for (Scene* scene: m_scenes){
		delete scene;
	}
	m_scenes.clear();
}

void SceneManager::Init(){
	m_nextScene = nullptr;
	Scene2* s = new Scene2();
	m_currentScene = s;
	m_currentScene->Init();
}

void SceneManager::RemoveScene(Scene* _scene){
	for (int i = 0; i < m_scenes.size(); i++){
		if (m_scenes[i] == _scene){
			m_scenes.erase(m_scenes.begin() + i);
			break;
		}
	}
}

void SceneManager::RemoveScene(int _scene_number){
	m_scenes.erase(m_scenes.begin() + _scene_number);
}


void SceneManager::AddScene(Scene* _scene){
	m_scenes.push_back(_scene);
}

void SceneManager::ChangeScene(){

	if (m_nextScene != nullptr){
		for (int i = 0; i < m_scenes.size(); i++){
			delete m_scenes[i];
		}
		delete m_currentScene;
		m_currentScene = m_nextScene;
		m_nextScene = nullptr;

		m_currentScene->Init();
		m_currentScene->Start();
	}
}

Scene* SceneManager::GetCurrentScene(){
	return m_currentScene;
}


void SceneManager::SetCurrentScene(Scene* _scene){
	m_currentScene = _scene;
}

void SceneManager::SetNextScene(Scene* _scene){
	m_nextScene = _scene;
}


