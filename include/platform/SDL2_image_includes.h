//
// Created by beyon on 2/18/2024.
//

#ifndef SDL2_IMAGE_INCLUDES_H
#define SDL2_IMAGE_INCLUDES_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <SDL_image.h>
#else
    #include <SDL2/SDL_image.h>
#endif

#endif //SDL2_IMAGE_INCLUDES_H
