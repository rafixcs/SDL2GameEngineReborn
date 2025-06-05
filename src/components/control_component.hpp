#ifndef CONTROLCOMPONENT_HPP
#define CONTROLCOMPONENT_HPP
#include "component.hpp"
#include "transform_component.hpp"


namespace Components {
    class ControlComponent : public Component {
    public:
        ControlComponent();
        void Initialize() override;
        void Update(float dt) override;
        void Render() override;
    private:
        TransformComponent* transform;
        SDL_Event* event;
    };
}




#endif //CONTROLCOMPONENT_HPP
