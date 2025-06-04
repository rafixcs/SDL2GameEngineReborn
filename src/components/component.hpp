#ifndef __COMPONENET_HPP__
#define __COMPONENET_HPP__

#include "../entities/entity.hpp"

namespace Entities
{
    class Entity;
}
namespace Components
{
    class Component
    {
        public:
            Entities::Entity *owner;
            Component() {};
            virtual void Initialize() = 0;
            virtual void Update(float dt) = 0;
            virtual void Render() = 0;
    };
}

#endif