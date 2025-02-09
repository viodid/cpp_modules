#include "../include/Fixed.hpp"


int main( void ) {
	Fixed a(20.5f);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(a + b);
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << c / Fixed(2) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
