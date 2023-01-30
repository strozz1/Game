#include "Entity.h"
#include "../../../vendor/entt.hpp"
#include "Scene.h"



Entity::Entity(entt::entity handle, Scene* scene1)
	: m_EntityHandle(handle), scene(scene1)
{
}

Entity::~Entity()
{
}
