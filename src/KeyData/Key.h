#ifndef WARCRAFTKEYCOUNTVISUALISER_KEY_H
#define WARCRAFTKEYCOUNTVISUALISER_KEY_H
#define DUNGEON_PLAYER_COUNT 5

#include <string>
#include "Player.h"

enum GameSeason {
    GameSeason_Invalid,
    GameSeason_TwwSeasonOne,
};

std::string SeasonToString(const GameSeason season);
GameSeason StringToSeason(const std::string& seasonString);

enum CompletionState {
    CompletionState_Invalid,
    CompletionState_Timed,
    CompletionState_FailedToTime,
    CompletionState_Abandoned,
};

std::string CompletionStateToString(const CompletionState state);
CompletionState StringToCompletionState(const std::string& completionString);

struct Key
{
    std::string RecordingPlayerName;
    Player Players[DUNGEON_PLAYER_COUNT];
    std::string DungeonName = "Invalid";
    int32_t Level = 0;
    CompletionState Completed = CompletionState_Invalid;
    int32_t TimeLimit = 0; // In Seconds
    int32_t CompletionTime = 0; // In Seconds
    int32_t Deaths = 0;
    // Date
    GameSeason Season = GameSeason_Invalid;

    friend std::ostream& operator<<(std::ostream& os, const Key& key);
};

#endif //WARCRAFTKEYCOUNTVISUALISER_KEY_H
