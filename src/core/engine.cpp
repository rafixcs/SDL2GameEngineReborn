#include "engine.hpp"
#include <SDL2/SDL.h>

#include <iostream>

Engine::RebornEngine::RebornEngine()
{
    if (this->initialize() == 0)
    {
        std::cout << "Initialized Engine!\n";
    }
    else
    {
        std::cerr << "Failed to Init Engine\n";
    }
}

auto Engine::RebornEngine::initialize() -> int
{
    std::cout << "Initializng modules...\n";

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL could not be initialized. SDL_Error: " << SDL_GetError() << "\n";
        return -1;
    }

    this->window = SDL_CreateWindow(
        "tmp title",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        460,
        340,
        SDL_WINDOW_SHOWN
    );

    if (this->window == nullptr)
    {
        std::cerr << "Window could not be created. SDL_Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return -1;
    }

    this->render = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->render == nullptr)
    {
        std::cerr << "Renderer could not be created. SDL_Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(this->window);
        SDL_Quit();
        return -1;
    }

    return 0;
}

auto Engine::RebornEngine::Build() -> std::shared_ptr<RebornEngine>
{
    std::cout << "test\n";
    return std::shared_ptr<Engine::RebornEngine>(new Engine::RebornEngine());
}

auto Engine::RebornEngine::Run() -> void
{
    
    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }

        SDL_SetRenderDrawColor(this->render, 0, 100, 200, 255);
        SDL_RenderClear(this->render);

        SDL_Rect myRect = { 300, 250, 200, 100};
        SDL_SetRenderDrawColor(this->render, 255, 0, 0, 255);
        SDL_RenderFillRect(this->render, &myRect);

        SDL_RenderPresent(this->render);
    }

    SDL_DestroyRenderer(this->render);
    SDL_DestroyWindow(this->window);
    SDL_Quit();

}
