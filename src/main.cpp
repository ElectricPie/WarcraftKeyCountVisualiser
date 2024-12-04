#define TEST_CSV_FILEPATH ""

#include <iostream>
#include "CsvReader.h"
#include "KeyData/Key.h"

int main()
{
    std::vector<Key> keys = CsvReader::ReadCsv(TEST_CSV_FILEPATH);
    std::cout << "Keys: " << keys.size() << "\n";
    for (auto& key : keys) {
        std::cout << key.DungeonName << "\n";
    }

    return 0;
}
