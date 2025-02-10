#include "../include/Point.hpp"

int main() {
    const Point a(0.0, 0.0);
    const Point b(0.0, 1.0);
    const Point c(1.0, 0.0);
    const Point point(0.9, 0.0);

    const bool inside = bsp(a, b, c, point);

    if(inside) {
        std::cout << "The point is inside the triangle." << std::endl;
    } else {
        std::cout << "The point is outside the triangle." << std::endl;
    }
    return 0;
}
