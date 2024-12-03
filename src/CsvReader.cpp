#define CSV_DELIMITER ','

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "CsvReader.h"
#include "KeyData/Key.h"

void CsvReader::ReadCsv(const std::string &filename)
{
    std::cout << "Reading " << filename << '\n';

    std::vector<std::pair<std::string, std::vector<std::string>>> data;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file");
        // TODO: Return data
    }

    std::string line;

    // Headers
    if (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string field;

        while (std::getline(ss, field, CSV_DELIMITER))
        {
            data.push_back({field, std::vector<std::string>{}});
        }
    }

    // Data
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
        newKey.DungeonName = row[1];
        newKey.Level = GetIntFromString(row[2]);
        newKey.Completed = StringToCompletionState(row[3]);
        newKey.TimeLimit = GetIntFromString(row[4]);
        newKey.CompletionTime = GetIntFromString(row[5]);
        newKey.Deaths = GetIntFromString(row[7]);
        newKey.Season = StringToSeason(row[9]);

        std::cout << newKey << "\n\n";
    }

    std::cout << '\n' << "Finished Reading CSV" << '\n';

    file.close();

    // TODO: ReadData
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