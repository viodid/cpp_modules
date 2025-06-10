#include "../include/easyfind.hpp"
#include <iostream>
#include <ostream>
#include <vector>

int main(void)
{
    try {
        std::vector<int> v;
        v.push_back(3);
        v.push_back(2);
        v.push_back(1);
        v.push_back(42);
        v.push_back(53);
        std::cout << easyfind(v, 42).size() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
