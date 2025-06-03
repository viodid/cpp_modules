#include "../include/Templates.hpp"
#include <iostream>
#include <ostream>

static int double_int(int n);
static char capitalize(char ch);

int main(void)
{
    std::cout << "== TEST 1 ==" << std::endl;
    int len = 4;
    int nArr[] = { 1, 2, 3, 4 };
    ::iter(nArr, len, double_int);
    for (int i = 0; i < len; i++) {
        std::cout << nArr[i] << std::endl;
    }
    std::cout << "== TEST 2 ==" << std::endl;
    std::string strArr = "Hey there!";
    ::iter((char*)strArr.c_str(), strArr.size(), capitalize);
    std::cout << strArr << std::endl;

    return 0;
}

static int double_int(int n)
{
    return n * 2;
}

static char capitalize(char ch)
{
    return (static_cast<int>(ch) >= 97 ? ch - 32 : ch);
}
