#include "../include/easyfind.hpp"
#include <iostream>
#include <ostream>
#include <vector>

#define SIZE 10

int main(void)
{
    // TODO: use random and iterators to fill up the containers
    // Use 4 types of containers
    try {
        srand(time(NULL));

        std::vector<int> v;
        for (int i = 0; i < SIZE; i++) {
            int randN = rand() % SIZE;
            std::cout << "index " << i + 1 << ":\t" << randN << std::endl;
            v.push_back(randN);
        }
        int toBeFound = rand() % SIZE + 3;
        std::cout << "to be found:\t" << toBeFound << std::endl;
        std::cout << *easyfind(v, toBeFound) << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
