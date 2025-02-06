#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(int n);
	Fixed(float f);
	Fixed(Fixed& copy);
	Fixed& operator=(Fixed& copy);
	~Fixed();

	int getRawBits();
	void setRawBits(int raw);
	float toFloat() const;
	int toInt() const;

private:
	int _value;
	static const int _fracBits = 8;
};

#endif
