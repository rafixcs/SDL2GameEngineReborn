#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <string>
#include <vector>

#include "entity_manager.hpp"
#include "../components/component.hpp"

namespace Components
{
    class Component;
}
namespace Entities
{
    class EntityManager;

    class Entity
    {
    public:
        Entity(EntityManager *manager, const std::string &name);
        
        /// @brief Initialize all components
        /// @return void
        auto Initialize() -> void;


        /// @brief Update all components
        /// @param dt delta time
        /// @return void
        auto Update(const float &dt) -> void;
        auto Render() -> void;

        template <typename T, typename... TArgs>
        auto AddComponent(TArgs &&...args) -> T &;

    private:
        EntityManager *manager;
        std::string name;

        std::vector<Components::Component *> componentsList;
    };

    template <typename T, typename... TArgs>
    inline auto Entity::AddComponent(TArgs &&...args) -> T &
    {
        T *newComponent(new T(std::forward<TArgs>(args)...));
        newComponent->owner = this;

        this->componentsList.emplace_back(newComponent);

        newComponent->Initialize();

        return *newComponent;
    }
}

#endif