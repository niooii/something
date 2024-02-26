#include <iostream>

#include <app.h>

#include "logging/logger.h"
#include <spdlog/spdlog.h>

// needed for windows for some reason
#undef main

int main(int argc, char* argv[]) {
    spdlog::set_level(spdlog::level::debug);
    App app = App{
        "hehehehaw",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        Render::BackendType::OPENGL};

    while (!app.should_quit())
    {
        app.DrawFrame();
        app.Update();
    }

    return 0;
}
