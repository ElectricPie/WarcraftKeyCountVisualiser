#include <unordered_map>
#include <ostream>
#include "Key.h"

std::string SeasonToString(const GameSeason season)
{
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

GameSeason StringToSeason(const std::string &seasonString)
{
    static const std::unordered_map<std::string, GameSeason> seasonMap = {
            {"TheWarWithin-1", GameSeason_TwwSeasonOne},
    };

    auto it = seasonMap.find(seasonString);
    return (it != seasonMap.end()) ? it->second : GameSeason_Invalid;
}

std::string CompletionStateToString(const CompletionState state)
{
    std::string stateString = "MISSING STATE";
    switch (state)
    {
        case CompletionState_Invalid:
            stateString = "INVALID";
            break;
        case CompletionState_Timed:
            stateString = "Timed";
            break;
        case CompletionState_FailedToTime:
            stateString = "Failed To TIme";
            break;
        case CompletionState_Abandoned:
            stateString = "Abandoned";
            break;
    }

    return stateString;
}

CompletionState StringToCompletionState(const std::string &completionString)
{
    static const std::unordered_map<std::string, CompletionState> completionMap = {
            {"Timed", CompletionState_Timed},
            {"Failed to time", CompletionState_FailedToTime},
            {"Abandoned", CompletionState_Abandoned},
    };

    auto it = completionMap.find(completionString);
    return (it != completionMap.end()) ? it->second : CompletionState_Invalid;
}

std::ostream &operator<<(std::ostream &os, const Key &key)
{
    os << key.DungeonName << "\n{\n" <<
       "   Recorder: " << key.RecordingPlayerName << "\n" <<
       "   Level: " << key.Level << "\n" <<
       "   Completed: " << CompletionStateToString(key.Completed) << "\n" <<
       "   Time: " << key.CompletionTime << "/" << key.TimeLimit << "\n" <<
       "   Deaths: " << key.Deaths << "\n" <<
       "   Season: " << SeasonToString(key.Season) << "\n" <<
       "   Players: " << "\n";
    for (int i = 0; i < DUNGEON_PLAYER_COUNT; i++) {
        os << key.Players[i] << "\n";
    }
    os << "}";

    return os;
}
