#include "../include/BitcoinExchange.hpp"

static void validateRowData(const std::string& row)
{
}

BitcoinExchange::BitcoinExchange(const std::string& dbPath)
{
    std::cout << "Parsing DB into memory" << std::endl;

    std::ifstream file(dbPath);
    if (!file.is_open()) {
        throw ErrorOpenFile();
    }
    std::string buffer;
    while (std::getline(file, buffer)) {
        validateRowData(buffer);
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Removing in memory DB" << std::endl;
}
