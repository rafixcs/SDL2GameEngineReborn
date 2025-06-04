#ifndef __TRANSFORM_COMPONENT_HPP__
#define __TRANSFORM_COMPONENT_HPP__

#include "component.hpp"
#include "../core/engine.hpp"
#include <SDL2/SDL.h>

namespace Components
{
    class TransformComponent : public Component {
        public:
            TransformComponent(const int& x, const int& y, const int& w, const int& h);
            virtual void Initialize();
            virtual void Update(float dt);
            virtual void Render();

        private:
            SDL_Rect rect{};
            std::shared_ptr<Engine::RebornEngine> engine;
            SDL_Renderer* render{};
    };
}

#endif