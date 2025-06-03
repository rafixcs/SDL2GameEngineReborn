#include "engine.hpp"
#include <SDL2/SDL.h>

#include <iostream>

auto Engine::RebornEngine::initialize() -> void
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL could not be initialized. SDL_Error: " << SDL_GetError() << "\n";
        return;
    }

    SDL_Window* window = SDL_CreateWindow(
        "tmp title",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        460,
        340,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr)
    {
        std::cerr << "Window could not be created. SDL_Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return;
    }

    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (render == nullptr)
    {
        std::cerr << "Renderer could not be created. SDL_Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }

        SDL_SetRenderDrawColor(render, 0, 100, 200, 255);
        SDL_RenderClear(render);

        SDL_Rect myRect = { 300, 250, 200, 100};
        SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
        SDL_RenderFillRect(render, &myRect);

        SDL_RenderPresent(render);
    }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

auto Engine::RebornEngine::Build() -> std::shared_ptr<RebornEngine>
{
    return std::shared_ptr<RebornEngine>();
}

auto Engine::RebornEngine::Run() -> void
{
    std::cout << "it's running!\n";
}
