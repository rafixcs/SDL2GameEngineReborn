#include "transform_component.hpp"

#include <iostream>

Components::TransformComponent::TransformComponent(const int &x, const int &y, const int &w, const int &h)
{
    this->rect = {x, y, w, h};
}

void Components::TransformComponent::Initialize()
{
    this->engine = Engine::RebornEngine::CreateOrGetInstance();
    this->render = this->engine->GetRender();
}

void Components::TransformComponent::Update(float dt)
{

}

void Components::TransformComponent::Render()
{
    SDL_SetRenderDrawColor(this->render, 255, 0, 0, 255);
    SDL_RenderFillRect(this->render, &this->rect);
}

