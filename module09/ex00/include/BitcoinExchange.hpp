#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <cfloat>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <time.h>

typedef struct tm t_date;

class BitcoinExchange {
private:
    std::map<t_date*, float> _db;

    void _parseRowData(const std::string& row);
    t_date* _parseDate(const std::string& date) const;
    unsigned int _parseAmount(const std::string& amount) const;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& cp);
    BitcoinExchange& operator=(const BitcoinExchange& cp);

    void parseDataFromFile(const std::string& filePath);
    void calculateTotal(const std::string& date, const std::string& amount) const;

    class ErrorOpenFile : public std::exception {
        virtual const char* what() const throw();
    };
    class WrongDateFormat : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif
