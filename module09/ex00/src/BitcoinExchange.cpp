#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
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
    std::ifstream file;
    file.open("data.csv");
    if (!file.is_open()) {
        throw ErrorOpenFile();
    }
    std::cout << "Parsing DB into memory" << std::endl;
    _rowFileApply(&BitcoinExchange::_parseRowDB, file);
    file.close();
    std::cout << "DB created successfully" << std::endl;
}

void BitcoinExchange::_parseRowDB(const std::string& row)
{
    std::string date = row.substr(0, row.find_first_of(","));
    std::string price = row.substr(row.find_first_of(",") + 1, std::string::npos);
    t_date* tdate = _parseDate(date);
    float fprice = std::atof(price.c_str());
    _db[tdate] = fprice;
}

// generic helpers

void BitcoinExchange::_parseHeader(const std::string& header) const
{
    if (header == "date,exchange_rate")
        return;
    if (header != "date | value")
        throw WrongHeader();
}

t_date* BitcoinExchange::_parseDate(const std::string& date) const
{
    t_date* tm = new t_date;
    char* parseTime = strptime(date.c_str(), "%Y-%m-%d", tm);
    if (!parseTime || *parseTime != '\0') {
        delete tm;
        throw WrongDateFormat();
    }
    tm->tm_mon++;
    tm->tm_year = tm->tm_year + 1900;
    if (tm->tm_mday > 31) {
        delete tm;
        throw WrongDateFormat();
    }
    return tm;
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

// Parse Input File
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

void BitcoinExchange::_parseRowData(const std::string& row)
{
    const std::string delimeter = " | ";
    if (row.find(delimeter) == std::string::npos) {
        std::cerr << "Error: wrong input format" << std::endl;
        return;
    }
    const std::string sdate = row.substr(0, row.find_first_of(delimeter));
    const std::string samount = row.substr(row.find_first_of(delimeter) + 3, std::string::npos);
    t_date* date = NULL;
    try {
        date = _parseDate(sdate);
        float amount = _parseAmount(samount);
        std::cout << sdate
                  << " => " << amount
                  << " = " << _calculateAmount(date, amount)
                  << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    if (date)
        delete date;
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
    if (f == 0)
        throw WrongInput();
    return f;
}

float BitcoinExchange::_calculateAmount(t_date* date, float amount)
{
    int year = date->tm_year;
    int month = date->tm_mon;
    int day = date->tm_mday;
    std::map<t_date*, float>::iterator it = _db.end();
    it--; // last pair
    int diff = it->first->tm_year - year;
    while (diff > 0 && it != _db.begin()) {
        it--;
        diff = it->first->tm_year - year;
    }
    if (diff > 0 && it == _db.begin())
        throw DateTooEarly();
    year = it->first->tm_year;
    diff = it->first->tm_mon - month;
    while (diff > 0 && it != _db.begin()) {
        if (year != it->first->tm_year)
            return it->second * amount;
        it--;
        diff = it->first->tm_mon - month;
    }
    if (diff > 0 && it == _db.begin())
        throw DateTooEarly();
    month = it->first->tm_mon;
    diff = it->first->tm_mday - day;
    while (diff > 0 && it != _db.begin()) {
        if (month != it->first->tm_mon)
            break;
        it--;
        diff = it->first->tm_mday - day;
    }
    if (diff > 0 && it == _db.begin())
        throw DateTooEarly();
    return it->second * amount;
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

const char* BitcoinExchange::DateTooEarly::what() const throw()
{
    return "Date is too early, no records found.";
}

const char* BitcoinExchange::WrongInput::what() const throw()
{
    return "Error: wrong input format";
}
