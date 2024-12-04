#ifndef WARCRAFTKEYCOUNTVISUALISER_CSVREADER_H
#define WARCRAFTKEYCOUNTVISUALISER_CSVREADER_H

#include <vector>

struct Key;

class CsvReader
{
public:
    static std::vector<Key> ReadCsv(const std::string& filename);

private:
    static int32_t GetIntFromString(const std::string& stringInput, int InvalidReturn = -1);
};


#endif //WARCRAFTKEYCOUNTVISUALISER_CSVREADER_H
