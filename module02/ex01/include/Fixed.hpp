#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& copy);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int raw);
	float toFloat() const;
	int toInt() const;

private:
	int _value;
	static const int _fracBits = 8;
};

std::ostream& operator<<(std::ostream& outputStream, const Fixed& obj);
#endif
