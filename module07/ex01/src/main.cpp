#include "../include/Templates.hpp"
#include <iostream>
#include <ostream>

static int double_int(int n);
static std::string capitalize(std::string str);

int main(void)
{
    std::cout << "== TEST 1 ==" << std::endl;
    int len = 4;
    int nArr[] = { 1, 2, 3, 4 };
    ::iterate(nArr, len, double_int);
    for (int i = 0; i < len; i++) {
        std::cout << nArr[i] << std::endl;
    }
    std::cout << "== TEST 2 ==" << std::endl;
    const std::string strArr[] = { "Hey there!", "how you doing" };
    ::iterate(strArr, 2, capitalize);
    for (int i = 0; i < 2; i++) {
        std::cout << strArr[i] << std::endl;
    }

    return 0;
}

static int double_int(int n)
{
    return n * 2;
}

static std::string capitalize(std::string str)
{
    for (size_t i = 0; i < str.length(); i++) {
        char ch = str[i];
        str[i] = static_cast<int>(ch) >= 97 ? ch - 32 : ch;
    }
    return str;
}
