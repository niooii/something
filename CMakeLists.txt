cmake_minimum_required(VERSION 3.28)
project(horse)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(SDL_net REQUIRED)
find_package(SDL_ttf REQUIRED)
# manually get the include path for SDL_gpu
set(GLM_INCLUDE_DIRS "/usr/include/glm")

# Include directories
include_directories(
        #my own shit
        "include"
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_PATH}
        ${SDL_MIXER_INCLUDE_DIRS}
        ${SDL_NET_INCLUDE_DIRS}
        ${SDL_TTF_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)

add_executable(horse main.cpp
        include/app.cpp
        include/app.h
        include/render/render_component.cpp
        include/render/render_component.h
        include/object_info.cpp
        include/object_info.h
        include/game/entity/entity_base.cpp
        include/game/entity/entity_base.h
        include/game/entity/entity_types.h
        include/game/geometry/rect.cpp
        include/game/geometry/rect.h
        include/game/geometry/point.cpp
        include/game/geometry/point.h
        include/game/geometry/circle.cpp
        include/game/geometry/circle.h
)

target_link_libraries(horse
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL_MIXER_LIBRARIES}
        ${SDL_NET_LIBRARIES}
        ${SDL_TTF_LIBRARIES}
)