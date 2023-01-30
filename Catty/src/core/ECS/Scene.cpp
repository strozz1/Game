#include <string>
#include "Scene.h"
#include "Entity.h"
#include "Component.h"
Scene::Scene()
{
}

Scene::~Scene()
{
}

Entity Scene::CreateEntity(const std::string& name)
{
	Entity entity = { registry.create(),this };
	entity.AddComponent<TransformComponent>();
	auto& tag=entity.AddComponent<TagComponent>();
	tag.Tag = name.empty() ? "Entity" : name;
	return entity;
}

//Creates an entity from entt and returns a Entity type


void Scene::onUpdate()
{
}
