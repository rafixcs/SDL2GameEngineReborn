#ifndef __ENGINE__
#define __ENGINE__

#include <memory>
#include <SDL2/SDL.h>

namespace Engine 
{
    class RebornEngine
    {
        private:
            RebornEngine();
            auto initialize() -> int;

        public:
            static auto Build() -> std::shared_ptr<RebornEngine>;
            auto Run() -> void;

        private:
            SDL_Window* window;
            SDL_Renderer* render;
        
    };

}


#endif