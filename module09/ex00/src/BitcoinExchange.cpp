#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string& file_path)
{
    _parseDB();
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Removing in memory DB" << std::endl;
    std::map<t_date*, float>::iterator it;
    for (it = _db.begin(); it != _db.end(); it++) {
        delete it->first;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cp) { (void)cp; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& cp)
{
    (void)cp;
    return *this;
}

void BitcoinExchange::_parseDB()
{
    std::cout << "Parsing DB into memory" << std::endl;
    std::ifstream file;
    file.open("../data.csv");
    if (!file.is_open()) {
        throw ErrorOpenFile();
    }
    _rowFileApply();
    file.close();
    std::cout << "DB created successfully" << std::endl;
}

void BitcoinExchange::_rowFileApply(void (BitcoinExchange::*f)(const std::string& content), std::ifstream& file)
{
    std::string buffer;
    std::getline(file, buffer);
    _parseHeader(buffer);
    while (std::getline(file, buffer)) {
        (this->*f)(buffer);
    }
}

void BitcoinExchange::_parseRowDB(const std::string& row)
{
    std::string date = row.substr(0, row.find_first_of(","));
    std::string price = row.substr(row.find_first_of(",") + 1, std::string::npos);
    t_date* tdate = _parseDate(date);
    float fprice = std::atof(price.c_str());
    _db[tdate] = fprice;
}

void BitcoinExchange::parseInputFile(const std::string& filePath)
{
    std::ifstream file;
    file.open(filePath.c_str());
    if (!file.is_open()) {
        throw ErrorOpenFile();
    }
    _rowFileApply(&BitcoinExchange::_parseRowData, file);
    file.close();
}

void BitcoinExchange::_parseHeader(const std::string& header) const
{
    // TODO: check wether the csv file can contain different separators
    if (header == "date,exchange_rate")
        return;
    if (header != "date | value")
        throw WrongHeader();
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
        const std::string untrimmedAmount = row.substr(row.find_first_of(delimeter), std::string::npos);
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
    if (f > 1000)
        throw ValueTooLarge();
    if (f < 0)
        throw ValueTooLow();
    return f;
}

// Exceptions
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

const char* BitcoinExchange::WrongHeader::what() const throw()
{
    return "Header is missing or have a wrong format";
}
