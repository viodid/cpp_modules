#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed& copy);
	Fixed& operator=(Fixed& copy);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int raw);

private:
	int _value;
	static const int _fracBits = 8;
};

#endif
