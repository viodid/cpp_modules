#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, float> _pricesDB;

public:
    BitcoinExchange(const std::string& filePath);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& cp);
    BitcoinExchange& operator=(const BitcoinExchange& cp);
};

#endif
