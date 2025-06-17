#include "../include/MutantStack.hpp"
#include <iostream>
#include <list>
#include <ostream>

int main()
{
    std::cout << "== STACK ==" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "begin:\t" << *it << std::endl;
    std::cout << "end:\t" << *ite << std::endl;
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "== LIST ==" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::cout << l.back() << std::endl;
    l.erase(--l.end());
    std::cout << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);
    std::list<int>::iterator lit = l.begin();
    std::cout << "begin:\t" << *(l.begin()) << std::endl;
    std::cout << "end:\t" << *(--l.end()) << std::endl;
    ++lit;
    --lit;
    while (lit != l.end()) {
        std::cout << *lit << std::endl;
        ++lit;
    }
    return 0;
}
