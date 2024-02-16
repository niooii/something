cmake_minimum_required(VERSION 3.28)
project(SDLGameFramework)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(SDL_net REQUIRED)
find_package(SDL_ttf REQUIRED)
# manually get the include path for SDL_gpu
set(SDL2_GPU_INCLUDE_DIRS "/usr/include/SDL2")
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
        ${SDL2_GPU_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)

add_executable(SDLGameFramework main.cpp
        include/app.cpp
        include/app.h
        include/render_component.cpp
        include/render_component.h
        include/result.h)
