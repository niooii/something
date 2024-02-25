cmake_minimum_required(VERSION 3.28)
project(horse)

set(CMAKE_CXX_STANDARD 23)

if(WIN32)
    set(SDL2_INSTALL "E:\\libs\\SDL2-2.28.5")
    set(SDL2_image_INSTALL "E:\\libs\\SDL2_image-2.8.2")
    set(SDL2_mixer_INSTALL "E:\\libs\\SDL2_mixer-2.8.0")
    set(SDL2_ttf_INSTALL "E:\\libs\\SDL2_ttf-2.22.0")
    set(SDL2_net_INSTALL "E:\\libs\\SDL2_net-2.2.0")
    set(spdlog_INSTALL "E:\\libs\\spdlog")
    # set directory accordingly
    set(SDL2_DIR "${SDL2_INSTALL}\\cmake")
    set(SDL2_image_DIR "${SDL2_image_INSTALL}\\cmake")
    set(SDL2_mixer_DIR "${SDL2_mixer_INSTALL}\\cmake")
    set(SDL2_ttf_DIR "${SDL2_ttf_INSTALL}\\cmake")
    set(SDL2_net_DIR "${SDL2_net_INSTALL}\\cmake")
    set(spdlog_DIR "${spdlog_INSTALL}\\cmake")
endif ()

add_library(glad external/glad/include/glad/glad.h external/glad/include/KHR/khrplatform.h external/glad/src/glad.c)
include_directories(glad external/glad/include)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_net REQUIRED)
if(NOT WIN32)
    find_package(fmt REQUIRED)
endif ()

find_package(spdlog REQUIRED)
# manually get the include path for SDL_gpu

# Include directories
if(WIN32)
    include_directories(
            #my own shit
            "include"
            ${SDL2_INCLUDE_DIRS}
            "${SDL2_image_INSTALL}\\include"
            "${SDL2_mixer_INSTALL}\\include"
            "${SDL2_net_INSTALL}\\include"
            "${SDL2_ttf_INSTALL}\\include"
            "${spdlog_INSTALL}\\include"
    )
else ()
    include_directories(
            #my own shit
            "include"
            ${SDL2_INCLUDE_DIRS}
            ${SDL2_image_INCLUDE_DIRS}
            ${SDL2_MIXER_INCLUDE_DIRS}
            ${SDL2_NET_INCLUDE_DIRS}
            ${SDL2_TTF_INCLUDE_DIRS}
            ${spdlog_INCLUDE_DIRS}
    )
endif ()

add_executable(horse main.cpp
        include/app.cpp
        include/app.h
        include/render/components/render_component.h
        include/game/entity/entity_base.cpp
        include/game/entity/entity_base.h
        include/game/entity/entity_types.h
        include/game/geometry/rect.cpp
        include/game/geometry/rect.h
        include/game/geometry/point.cpp
        include/game/geometry/point.h
        include/game/geometry/circle.cpp
        include/game/geometry/circle.h
        include/game/entity/player.cpp
        include/game/entity/player.h
        include/game/math/vec2.cpp
        include/game/math/vec2.h
        include/game/game.cpp
        include/game/game.h
        include/game/game_state.cpp
        include/game/game_state.h
        include/platform/SDL2_includes.h
        include/platform/SDL2_image_includes.h
        include/logging/logger.h
        include/logging/logger.h
        include/render/components/clickable_component.h
        include/render/components/ui/text_field.cpp
        include/render/components/ui/text_field.h
        include/render/Renderer.cpp
        include/render/Renderer.h
        include/render/Renderer.h
        include/render/backends/backend_types.h
        include/render/backends/renderer_interface.h
        include/render/backends/opengl/gl_renderer.cpp
        include/render/backends/opengl/gl_renderer.h
)

if (WIN32)
    target_link_libraries(horse
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        ${SDL2_NET_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${spdlog_LIBRARIES}
    )
else()
    target_link_libraries(horse
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        ${SDL2_NET_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${spdlog_LIBRARIES}
        fmt::fmt
    )
endif ()