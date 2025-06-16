#include "../include/Span.hpp"
#include <iostream>
#include <ostream>

#define SIZE 5

static Span fillSpan(Span& s);

int main(void)
{
    Span v(SIZE);
    srand(time(NULL));
    try {
        v = fillSpan(v);
        std::cout << "shortest:\t" << v.shortestSpan() << std::endl;
        std::cout << "largest:\t" << v.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

static Span fillSpan(Span& s)
{
    std::vector<int> inputVector;
    for (int i = 0; i < SIZE; i++) {
        int randN = rand() % 20;
        std::cout << "index " << i + 1 << ":\t" << randN << std::endl;
        inputVector.push_back(randN);
    }
    s.insertVector(inputVector);
    return s;
}
