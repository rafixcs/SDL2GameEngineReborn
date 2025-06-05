#include "engine.hpp"
#include <SDL2/SDL.h>
#include <iostream>

#include "../components/control_component.hpp"
#include "../entities/entity_manager.hpp"
#include "../entities/entity.hpp"
#include "../components/transform_component.hpp"
#include "../configs/constants.h"

std::shared_ptr<Engine::RebornEngine> Engine::RebornEngine::sInstance = Engine::RebornEngine::CreateOrGetInstance();

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
    std::cout << "Initializing modules...\n";

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL could not be initialized. SDL_Error: " << SDL_GetError() << "\n";
        return -1;
    }

    this->window = SDL_CreateWindow(
        TITLE.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);

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

    this->entitiesManager = std::shared_ptr<Entities::EntityManager>(new Entities::EntityManager());
    this->event = new SDL_Event();
    return 0;
}

auto Engine::RebornEngine::load() -> void
{
    Entities::Entity* entity = new Entities::Entity(this->entitiesManager.get(), "test");
    entity->AddComponent<Components::TransformComponent>(300, 250, 200, 100);
    this->entitiesManager->AddEntity("test", entity);

    Entities::Entity* entity2 = new Entities::Entity(this->entitiesManager.get(), "test");
    entity2->AddComponent<Components::TransformComponent>(0, 0, 100, 100);
    entity2->AddComponent<Components::ControlComponent>();
    this->entitiesManager->AddEntity("test", entity2);

    this->entitiesManager->InitializeEntities();
}

auto Engine::RebornEngine::CreateOrGetInstance() -> std::shared_ptr<RebornEngine>
{
    if (Engine::RebornEngine::sInstance == nullptr)
    {
        Engine::RebornEngine::sInstance = std::shared_ptr<Engine::RebornEngine>(new Engine::RebornEngine());
    }
    return Engine::RebornEngine::sInstance;
}

auto Engine::RebornEngine::Run() -> void
{
    this->load();

    bool quit = false;

    while (!quit)
    {
        SDL_PollEvent(this->event);
        if (this->event->type == SDL_QUIT)
        {
            quit = true;
        }
        else if (this->event->type == SDL_KEYDOWN)
        {
            if (this->event->key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }
        }

        /*int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - this->ticksLastFrame);
        if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME)
            SDL_Delay(timeToWait);

        // Delta time is the difference in ticks from last frame converted to seconds
        float deltaTime = (SDL_GetTicks() - this->ticksLastFrame) / 1000.0f;

        // Sets the new ticks for the current frame to be used in the next pass
        this->ticksLastFrame = SDL_GetTicks();*/
        float deltaTime = 1.0f;
        deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;
        
        SDL_SetRenderDrawColor(this->render, 0, 100, 200, 255);
        SDL_RenderClear(this->render);

        entitiesManager->UpdateEntities(deltaTime);
        entitiesManager->RenderEntities();

        SDL_RenderPresent(this->render);
    }

    SDL_DestroyRenderer(this->render);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

auto Engine::RebornEngine::GetRender() -> SDL_Renderer *
{
    return this->render;
}

auto Engine::RebornEngine::GetWindow() -> SDL_Window *
{
    return this->window;
}

auto Engine::RebornEngine::GetEvent() -> SDL_Event*
{
    return this->event;
}

