//
// Created by rafaels on 6/4/25.
//

#include "control_component.hpp"
#include "transform_component.hpp"
#include <iostream>

Components::ControlComponent::ControlComponent() {
    this->transform = nullptr;
}

void Components::ControlComponent::Initialize()
{
    this->transform = this->owner->GetComponent<TransformComponent>();
    this->event = Engine::RebornEngine::CreateOrGetInstance()->GetEvent();
}

void Components::ControlComponent::Update(float dt)
{
    SDL_Keycode key = this->event->key.keysym.sym;

    if (this->event->type == SDL_KEYDOWN)
    {
        const int value = 100;
        if (key == SDLK_UP)
        {
            this->transform->rect.y -= value * dt;
        }
        if (key == SDLK_DOWN)
        {
            this->transform->rect.y += value * dt;
        }
        if (key == SDLK_LEFT)
        {
            this->transform->rect.x -= value * dt;
        }
        if (key == SDLK_RIGHT)
        {
            this->transform->rect.x += value * dt;
        }
    }
}

void Components::ControlComponent::Render()
{

}
