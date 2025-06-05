#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <string>
#include <vector>
#include <map>
#include <boost/type_index.hpp>
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

        auto Initialize() -> void;
        auto Update(const float &dt) -> void;
        auto Render() -> void;

        template<typename T>
        auto GetComponent() -> T*;

        template <typename T, typename... TArgs>
        auto AddComponent(TArgs &&...args) -> T &;

    private:
        EntityManager *manager;
        std::string name;

        std::vector<Components::Component *> componentsList;
        std::map<const std::type_info *, Components::Component *> componentsLookup;
    };

    template <typename T, typename... TArgs>
    inline auto Entity::AddComponent(TArgs &&...args) -> T &
    {
        T *newComponent(new T(std::forward<TArgs>(args)...));
        newComponent->owner = this;

        this->componentsList.emplace_back(newComponent);
        this->componentsLookup[&typeid(*newComponent)] = newComponent;

        newComponent->Initialize();

        return *newComponent;
    }

    template<typename T>
    inline auto Entity::GetComponent() -> T*
    {
        return static_cast<T*>(this->componentsLookup[&typeid(T)]);
    }
}

#endif