#include "../include/easyfind.hpp"
#include <iostream>
#include <list>
#include <ostream>
#include <vector>

#define SIZE 10

template <typename T>
static void fillContainer(T* t);

int main(void)
{
    std::vector<int>* v = new std::vector<int>;
    std::list<int>* l = new std::list<int>;
    srand(time(NULL));
    int toBeFound = rand() % SIZE + 3;
    std::cout << "to be found:\t" << toBeFound << std::endl;
    try {
        std::cout << "== vector ==" << std::endl;
        fillContainer(v);
        std::cout << "found:\t" << *easyfind(*v, toBeFound) << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << " vector" << std::endl;
    }
    try {
        std::cout << "== list ==" << std::endl;
        fillContainer(l);
        std::cout << "found:\t" << *easyfind(*l, toBeFound) << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << " list" << std::endl;
    }
    delete v;
    delete l;
    return 0;
}

template <typename T>
static void fillContainer(T* t)
{
    for (int i = 0; i < SIZE; i++) {
        int randN = rand() % SIZE;
        std::cout << "index " << i + 1 << ":\t" << randN << std::endl;
        (*t).push_back(randN);
    }
}
