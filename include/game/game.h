//
// Created by beyon on 2/18/2024.
//

#ifndef GAME_H
#define GAME_H
#include "game_state.h"


class Game
{
private:
    const char* name_;
    GameState state_;
    bool should_quit_{false};

    bool LoadGameStateFromDisk();
    bool WriteGameStateToDisk();

public:
    Game(const char* name);
    Game(const char* name, bool override_last_save);

    // Accessors
    inline bool should_quit()
    {
        return should_quit_;
    }
};


#endif //GAME_H
