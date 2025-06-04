#include "entity_manager.hpp"

Entities::EntityManager::EntityManager()
{
}

auto Entities::EntityManager::AddEntity(const std::string &name, Entity* entity) -> void
{
    this->entities.emplace_back(entity);
}

auto Entities::EntityManager::InitializeEntities() -> void
{
    for (auto& entity: this->entities)
    {
        entity->Initialize();
    }
}

auto Entities::EntityManager::UpdateEntities(float dt) -> void
{
    for (auto& entity: this->entities)
    {
        entity->Update(dt);
    }
}

auto Entities::EntityManager::RenderEntities() -> void
{
    for (auto& entity: this->entities)
    {
        entity->Render();
    }
}
