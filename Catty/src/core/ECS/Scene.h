#pragma once
#ifndef SCENE_CLASS
#define SCENE_CLASS
#include <string>
#include "../../../vendor/entt.hpp"

class Entity;
class Scene
{

public:
	Scene();
	~Scene();

	Entity CreateEntity(const std::string& name = std::string());

	void onUpdate();
	void onRender();

private:

	entt::registry registry;

	friend class Entity;
};

#endif