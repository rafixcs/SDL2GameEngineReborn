#include "entity.hpp"
#include "../components/component.hpp"

Entities::Entity::Entity(EntityManager *manager, const std::string &name) : manager(manager), name(name)
{
}

auto Entities::Entity::Initialize() -> void
{
    return;
}

auto Entities::Entity::Update(const float &dt) -> void
{
    for (auto& component: this->componentsList)
    {
        component->Update(dt);
    }
}

auto Entities::Entity::Render() -> void
{
    for (auto& component: this->componentsList)
    {
        component->Render();
    }
}
