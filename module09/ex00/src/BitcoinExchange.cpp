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
        _parseRowData(buffer);
    }
    file.close();
}

void BitcoinExchange::_parseRowData(const std::string& row)
{
    const std::string delimeter = "|";
    const std::string whitespace = " \t";
    const std::string untrimmedDate = row.substr(0, row.find_first_of(delimeter));
    t_date* date = _parseDate(
        untrimmedDate.substr(
            untrimmedDate.find_first_not_of(whitespace),
            untrimmedDate.find_last_not_of(whitespace)));
    const std::string untrimmedAmount = row.substr(row.find_first_of(delimeter), row.size());
    float amount = _parseAmount(untrimmedAmount.substr(
        untrimmedAmount.find_first_not_of(whitespace),
        untrimmedAmount.find_last_not_of(whitespace)));
    _db[date] = amount;
}
t_date* BitcoinExchange::_parseDate(const std::string& date) const
{
    t_date* tm = new t_date;
    if (!strptime(date.c_str(), "%Y-%m-%d", tm)) {
        delete tm;
        throw WrongDateFormat();
    }
    return tm;
}
unsigned int BitcoinExchange::_parseAmount(const std::string& amount) const
{
}

const char* BitcoinExchange::ErrorOpenFile::what() const throw()
{
    return "Error: could not open file";
}

const char* BitcoinExchange::WrongDateFormat ::what() const throw()
{
    return "Error date: bad input";
}
