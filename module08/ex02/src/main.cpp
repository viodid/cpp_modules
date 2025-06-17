#include "../include/MutantStack.hpp"
#include <iostream>
#include <ostream>
#include <queue>

template <typename T>
static void tester(T& container);

int main()
{
    MutantStack<int> mstack;
    tester(mstack);
    std::queue<int> l;
    tester(l);
    return 0;
}

template <typename T>
static void tester(T& container)
{
    container.push(5);
    container.push(17);
    std::cout << container.top() << std::endl;
    container.pop();
    std::cout << container.size() << std::endl;
    container.push(3);
    container.push(5);
    container.push(737);
    container.push(0);
    MutantStack<int>::iterator it = container.begin();
    MutantStack<int>::iterator ite = container.end();
    std::cout << "begin:\t" << *it << std::endl;
    std::cout << "end:\t" << *ite << std::endl;
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}
