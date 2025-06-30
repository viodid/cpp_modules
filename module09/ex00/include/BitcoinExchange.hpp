#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <cfloat>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, float> _db;

    void _validateRowData(const std::string& row) const;
    void _validateDate(const std::string& date) const;
    void _validateAmount(const std::string& amount) const;
    void _calculateTotal(const std::string& date, const std::string& amount) const;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& cp);
    BitcoinExchange& operator=(const BitcoinExchange& cp);

    void parseDataFromFile(const std::string& filePath);

    class ErrorOpenFile : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif
