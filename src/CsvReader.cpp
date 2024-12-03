#define CSV_DELIMITER ','

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "CsvReader.h"

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
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;

        while (std::getline(ss, field, CSV_DELIMITER)) {
            data.push_back({field, std::vector<std::string> {}});
        }
    }

    // Data
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        int colIndex = 0;

        while (std::getline(ss, field, CSV_DELIMITER)) {
            if (!field.empty() && field.front() == '"' && field.back() != '"') {
                std::string remainder;
                while (std::getline(ss, remainder, CSV_DELIMITER)) {
                    field += CSV_DELIMITER + remainder;
                    if (!remainder.empty() && remainder.back() == '"') {
                        break;
                    }
                }

                if (!field.empty() && field.front() == '"' && field.back() == '"') {
                    field = field.substr(1, field.size() - 2);
                }
            }

            data.at(colIndex).second.push_back(field);
            colIndex++;
        }
    }

    for (auto& testLine : data) {
        std::cout << '\n' << '\n' << testLine.first << '\n';
        for (auto& test : testLine.second) {
            std::cout << test << " | ";
        }
    }


    std::cout << '\n' << "Finished Reading CSV" << '\n';

    file.close();

    // TODO: ReadData
}
