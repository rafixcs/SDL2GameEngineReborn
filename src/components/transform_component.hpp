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
            void Initialize() override;
            void Update(float dt) override;
            void Render() override;

            SDL_Rect rect{};
        private:
            std::shared_ptr<Engine::RebornEngine> engine;
            SDL_Renderer* render{};
    };
}

#endif