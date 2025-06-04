#ifndef __ENGINE__
#define __ENGINE__

#include <memory>
#include <SDL2/SDL.h>
#include "../entities/entity_manager.hpp"

namespace Engine 
{
    class RebornEngine
    {
        private:
            RebornEngine();
            auto initialize() -> int;
            auto load() -> void;
            static std::shared_ptr<RebornEngine> sInstance;

        public:
            static auto CreateOrGetInstance() -> std::shared_ptr<RebornEngine>;
            auto Run() -> void;
            auto GetRender() -> SDL_Renderer*;
            auto GetWindow() -> SDL_Window*;

        private:
            SDL_Window* window;
            SDL_Renderer* render;

            std::shared_ptr<Entities::EntityManager> entitiesManager;
    };

}


#endif