#ifndef __ENTITY_MANAGER_HPP__
#define __ENTITY_MANAGER_HPP__

#include <vector>
#include "entity.hpp"

namespace Entities
{
    class Entity;
    class EntityManager
    {
    public:
        EntityManager();

        auto AddEntity(const std::string &name, Entity *entity) -> void;
        auto InitializeEntities() -> void;
        auto UpdateEntities(float dt) -> void;
        auto RenderEntities() -> void;
        
        // get entities
        // destroy entities
        // check collission
        
    private:
        std::vector<Entity *> entities;
    };
}

#endif