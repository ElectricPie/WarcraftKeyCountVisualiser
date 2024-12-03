#ifndef WARCRAFTKEYCOUNTVISUALISER_KEY_H
#define WARCRAFTKEYCOUNTVISUALISER_KEY_H

#include <string>
#include "Player.h"

enum GameSeason {
    None,
    TwwSeasonOne,
};

enum CompletionState {
    Timed,
    FailedToTime,
    Abandoned,
};

struct Key
{
    Player Players[5];
    std::string DungeonName;
    int32_t Level;
    CompletionState Completed;
    int32_t TimeLimit;
    int32_t CompletionTime;
    int32_t Deaths;
    // Date
    GameSeason Season;
};


#endif //WARCRAFTKEYCOUNTVISUALISER_KEY_H
