#include "core/engine.hpp"

int main(int argc, char** argv)
{
    auto engine = Engine::RebornEngine::Build();
    engine->Run();
    return 0;
}
