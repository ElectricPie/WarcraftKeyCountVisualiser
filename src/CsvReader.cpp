#define CSV_DELIMITER ','
#define RECORDING_PLAYER_INDEX 0
#define DUNGEON_NAME_INDEX 1
#define DUNGEON_LEVEL_INDEX 2
#define COMPLETION_STATE_INDEX 3
#define TIME_LIMIT_INDEX 4
#define COMPLETION_TIME_INDEX 5
#define DEATHS_INDEX 7
#define SEASON_INDEX 9

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "CsvReader.h"
#include "KeyData/Key.h"

void CsvReader::ReadCsv(const std::string &filename)
{
    std::cout << "Reading " << filename << '\n';

    // TODO: Remove data as it will be stored in the structs
    std::vector<std::pair<std::string, std::vector<std::string>>> data;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file");
        // TODO: Return data
    }

    std::string line;

    // Read the Headers
    if (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string field;

        while (std::getline(ss, field, CSV_DELIMITER))
        {
            data.push_back({field, std::vector<std::string>{}});
        }
    }

    // Read the Data
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string field;
        int colIndex = 0;

        std::vector<std::string> row;
        // Handle entries that use commas
        while (std::getline(ss, field, CSV_DELIMITER))
        {
            if (!field.empty() && field.front() == '"' && field.back() != '"')
            {
                std::string remainder;
                while (std::getline(ss, remainder, CSV_DELIMITER))
                {
                    field += CSV_DELIMITER + remainder;
                    if (!remainder.empty() && remainder.back() == '"')
                    {
                        break;
                    }
                }
            }

            // Remove quotes
            if (!field.empty() && field.front() == '"' && field.back() == '"')
            {
                field = field.substr(1, field.size() - 2);
            }

            data.at(colIndex).second.push_back(field);
            row.push_back(field);
            colIndex++;
        }

        Key newKey;
        newKey.RecordingPlayerName = row[RECORDING_PLAYER_INDEX];
        newKey.DungeonName = row[DUNGEON_NAME_INDEX];
        newKey.Level = GetIntFromString(row[DUNGEON_LEVEL_INDEX]);
        newKey.Completed = StringToCompletionState(row[COMPLETION_STATE_INDEX]);
        newKey.TimeLimit = GetIntFromString(row[TIME_LIMIT_INDEX]);
        newKey.CompletionTime = GetIntFromString(row[COMPLETION_TIME_INDEX]);
        newKey.Deaths = GetIntFromString(row[DEATHS_INDEX]);
        newKey.Season = StringToSeason(row[SEASON_INDEX]);

        std::cout << newKey << "\n\n";
    }

    std::cout << '\n' << "Finished Reading CSV" << '\n';

    file.close();

    // TODO: Return Data
}

int32_t CsvReader::GetIntFromString(const std::string &stringInput)
{
    try {
        int num = std::stoi(stringInput);
        return num;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "'" << stringInput << ": not a number" << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "'" << stringInput << ": Number Too Larger" << std::endl;
    }

    return -1;
}