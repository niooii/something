cmake_minimum_required(VERSION 3.28)
project(horse)

set(CMAKE_CXX_STANDARD 23)

if(WIN32)
    # set directory accordingly
    set(SDL2_DIR "E:\\libs\\SDL2-2.28.5\\cmake")
    set(SDL2_image_DIR "E:\\libs\\SDL2_image-2.8.2\\cmake")
    set(SDL2_mixer_DIR "E:\\libs\\SDL2_mixer-2.8.0\\cmake")
    set(SDL2_ttf_DIR "E:\\libs\\SDL2_ttf-2.22.0\\cmake")
    set(SDL2_net_DIR "E:\\libs\\SDL2_net-2.2.0\\cmake")
endif ()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_net REQUIRED)
# manually get the include path for SDL_gpu

# Include directories
include_directories(
        #my own shit
        "include"
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_PATH}
        ${SDL2_MIXER_INCLUDE_DIRS}
        ${SDL2_NET_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
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
        include/game/entity/player.cpp
        include/game/entity/player.h
        include/game/math/vec2.cpp
        include/game/math/vec2.h
)

target_link_libraries(horse
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        ${SDL2_NET_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)