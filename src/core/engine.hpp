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
            auto GetEvent() -> SDL_Event*;

        private:
            SDL_Window* window;
            SDL_Renderer* render;
            SDL_Event* event;

            std::shared_ptr<Entities::EntityManager> entitiesManager;

            uint32_t ticksLastFrame;

            std::map<SDL_Keycode, bool> lookupKbKeysPressed;
    };

}


#endif