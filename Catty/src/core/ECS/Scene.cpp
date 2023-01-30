#include <string>
#include "Scene.h"
#include "Entity.h"
#include "Component.h"
#include "../../Logger/Logger.h"
#include "../Game.h"
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

void Scene::onRender()
{
	//Render all texture components
	auto view = registry.view<TransformComponent, TextureComponent>();
	for (auto entity : view) {
		auto& texture = view.get<TextureComponent>(entity);
		auto& transform = view.get<TransformComponent>(entity);

		SDL_RenderCopy(Game::renderer, texture.texture, &transform.srcRect, &transform.destRect);


	}
}
