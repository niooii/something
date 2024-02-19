#include <iostream>

#include <app.h>

#include "logging/logger.h"
#include <spdlog/spdlog.h>

// needed for windows for some reason
#undef main

int main(int argc, char* argv[]) {
    spdlog::set_level(spdlog::level::debug);
    App app = App{};
    for(int i = 0; i < 2000; i++) {
        std::cout << i << '\n';
    }
    for(int i = 0; i < 2000; i++) {
        spdlog::debug("hi {}", i);
    }
    return 0;
}
