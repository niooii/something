//
// Created by beyon on 2/18/2024.
//

#ifndef GAME_H
#define GAME_H
#include "game_state.h"


class Game
{
private:
    const char* name;
    GameState state;

    bool LoadGameStateFromDisk();
    bool WriteGameStateToDisk();

public:
    Game(const char* name);
    Game(const char* name, bool override_last_save);
};


#endif //GAME_H
