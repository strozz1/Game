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

		//Create rectangles
		SDL_Rect srcRect, destRect;
		//src rectangle
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = transform.size.x;
		srcRect.h = transform.size.y;

		//dest rectangle
		destRect.x = transform.position.x;
		destRect.y = transform.position.y;
		destRect.w = srcRect.w * transform.scale;
		destRect.h = srcRect.h * transform.scale;
		
		SDL_RenderCopy(Game::renderer, texture.texture, &srcRect, &destRect);


	}
}
