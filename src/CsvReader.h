#ifndef WARCRAFTKEYCOUNTVISUALISER_CSVREADER_H
#define WARCRAFTKEYCOUNTVISUALISER_CSVREADER_H


class CsvReader
{
public:
    static void ReadCsv(const std::string& filename);

private:
    static int32_t GetIntFromString(const std::string& stringInput);
};


#endif //WARCRAFTKEYCOUNTVISUALISER_CSVREADER_H
