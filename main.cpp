#include "src/core/engine.hpp"

int main(int argc, char** argv)
{
    auto engine = Engine::RebornEngine::CreateOrGetInstance();
    engine->Run();
    return 0;
}
