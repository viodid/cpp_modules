#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Removing in memory DB" << std::endl;
}

void BitcoinExchange::parseDataFromFile(const std::string& filePath)
{
    std::cout << "Parsing DB into memory" << std::endl;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw ErrorOpenFile();
    }
    std::string buffer;
    while (std::getline(file, buffer)) {
        _validateRowData(buffer);
    }
    file.close();
}

void BitcoinExchange::_validateRowData(const std::string& row) const
{
    std::string cp = row;
    std::string delimeter = "|";
    _validateDate(cp.substr(0, cp.find_first_of(delimeter)));
    _validateAmount(cp.substr(cp.find_first_of(delimeter), cp.size()));
}
void BitcoinExchange::_validateDate(const std::string& date) const { }
void BitcoinExchange::_validateAmount(const std::string& amount) const { }
