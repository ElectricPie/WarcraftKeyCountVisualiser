#ifndef WARCRAFTKEYCOUNTVISUALISER_KEY_H
#define WARCRAFTKEYCOUNTVISUALISER_KEY_H

#include <string>
#include <unordered_map>
#include "Player.h"

enum GameSeason {
    GameSeason_Invalid,
    GameSeason_TwwSeasonOne,
};

std::string SeasonToString(const GameSeason season) {
    std::string seasonString = "MISSING SEASON";
    switch (season)
    {
        case GameSeason_Invalid:
            seasonString = "INVALID";
            break;
        case GameSeason_TwwSeasonOne:
            seasonString = "TWW S1";
            break;
    }

    return seasonString;
}

GameSeason StringToSeason(const std::string& seasonString) {
    static const std::unordered_map<std::string, GameSeason> seasonMap = {
            {"TheWarWithin-1", GameSeason_TwwSeasonOne}
    };

    auto it = seasonMap.find(seasonString);
    return (it != seasonMap.end()) ? it->second : GameSeason_Invalid;
}

enum CompletionState {
    CompletionState_Invalid,
    CompletionState_Timed,
    CompletionState_FailedToTime,
    CompletionState_Abandoned,
};

struct Key
{
    Player Players[5];
    std::string DungeonName = "Invalid";
    int32_t Level = 0;
    CompletionState Completed = CompletionState_Invalid;
    int32_t TimeLimit = 0;
    int32_t CompletionTime = 0;
    int32_t Deaths = 0;
    // Date
    GameSeason Season = GameSeason_Invalid;

    friend std::ostream& operator<<(std::ostream& os, const Key& key) {
        os << key.DungeonName << "\n{\n" <<
        "   Level: " << key.Level << "\n" <<
        "   Completed: " << "\n" <<
        "   Time: " << key.CompletionTime << "/" << key.TimeLimit << "\n" <<
        "   Deaths: " << key.Deaths << "\n" <<
        "   Season: " << SeasonToString(key.Season) << "\n" <<
        "}";
        return os;
    }
};

#endif //WARCRAFTKEYCOUNTVISUALISER_KEY_H
