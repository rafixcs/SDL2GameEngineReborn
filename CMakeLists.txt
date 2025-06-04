cmake_minimum_required(VERSION 3.31)
project(GameEngineRebornCLion)

set(CMAKE_CXX_STANDARD 20)
find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME}
        main.cpp
        src/core/engine.cpp
        src/components/transform_component.cpp
        src/entities/entity.cpp
        src/entities/entity_manager.cpp
        src/configs/constants.h
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
