//
// Created by beyon on 2/18/2024.
//

#ifndef SDL2_INCLUDES_H
#define SDL2_INCLUDES_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

#endif //SDL2_INCLUDES_H
