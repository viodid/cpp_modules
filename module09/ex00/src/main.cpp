#include "../include/BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Wrong number of arguments" << std::endl;
        std::cerr << "Usage: " << argv[0] << "[path to file]" << std::endl;
    }
    try {
        BitcoinExchange be;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
