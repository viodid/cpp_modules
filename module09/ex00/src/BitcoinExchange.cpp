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

    std::ifstream file;
    file.open(filePath.c_str());
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
    try {
        t_date* date = _parseDate(
            untrimmedDate.substr(
                untrimmedDate.find_first_not_of(whitespace),
                untrimmedDate.find_last_not_of(whitespace)));
        const std::string untrimmedAmount = row.substr(row.find_first_of(delimeter), row.size());
        float amount = _parseAmount(untrimmedAmount.substr(
            untrimmedAmount.find_first_not_of(whitespace),
            untrimmedAmount.find_last_not_of(whitespace)));
        _db[date] = amount;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
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

float BitcoinExchange::_parseAmount(const std::string& amount) const
{
    if (amount == "0" || amount == "0.0")
        return 0;
    if (amount.size() > 30)
        throw ValueTooLarge();
    float f = std::atof(amount.c_str());
    if (f < 0)
        throw ValueTooLow();
    return f;
}

const char* BitcoinExchange::ErrorOpenFile::what() const throw()
{
    return "Error: could not open file";
}

const char* BitcoinExchange::WrongDateFormat ::what() const throw()
{
    return "Error date: bad input";
}

const char* BitcoinExchange::ValueTooLow ::what() const throw()
{
    return "Error amount: value is negative";
}

const char* BitcoinExchange::ValueTooLarge ::what() const throw()
{
    return "Error amount: value too large";
}
