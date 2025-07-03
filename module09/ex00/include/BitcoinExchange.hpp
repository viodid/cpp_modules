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

    void _parseHeader(const std::string& header) const;
    void _parseRowData(const std::string& row);
    t_date* _parseDate(const std::string& date) const;
    float _parseAmount(const std::string& amount) const;
    void _rowFileApply(void (BitcoinExchange::*f)(const std::string&), std::ifstream&);
    void _parseRowDB(const std::string& row);

    void _parseDB();

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& file_path);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& cp);
    BitcoinExchange& operator=(const BitcoinExchange& cp);

    void parseInputFile(const std::string& filePath);

    class ErrorOpenFile : public std::exception {
        virtual const char* what() const throw();
    };
    class WrongDateFormat : public std::exception {
        virtual const char* what() const throw();
    };
    class ValueTooLow : public std::exception {
        virtual const char* what() const throw();
    };
    class ValueTooLarge : public std::exception {
        virtual const char* what() const throw();
    };
    class WrongHeader : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif
