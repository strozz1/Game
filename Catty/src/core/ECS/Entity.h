#pragma once
#ifndef ENTITY_CLASS
#define ENTITY_CLASS
#include "../../../vendor/entt.hpp"
using namespace std;
#include "Scene.h"

class Entity
{

public:
	Entity(entt::entity handle, Scene* scene);
	~Entity();

	//Add component function
	template<typename T, typename... Args>
	T& AddComponent(Args&&... args) {
		assert(!HasComponent<T>());
		return scene->registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
	}

	//Get component from entity
	template<typename T>
	T& GetComponent() {
		return scene->registry.get<T>(m_EntityHandle);
	}

	//Remove component function
	template <typename T>
	void removeComponent() {
		assert(HasComponent<T>());
		scene->registry.remove<T>(m_EntityHandle);
	}


	//Check if entity has a specific component
	template <typename T>
	bool HasComponent() {
		return scene->registry.all_of<T>(m_EntityHandle);
	}



private:
	entt::entity m_EntityHandle;
	Scene* scene;


};

#endif