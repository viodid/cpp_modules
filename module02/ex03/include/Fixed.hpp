#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& obj);
	Fixed& operator=(const Fixed& obj);
	bool operator>(const Fixed& obj) const;
	bool operator<(const Fixed& obj) const;
	bool operator>=(const Fixed& obj) const;
	bool operator<=(const Fixed& obj) const;
	bool operator==(const Fixed& obj) const;
	bool operator!=(const Fixed& obj) const;
	Fixed operator+(const Fixed& obj) const;
	Fixed operator-(const Fixed& obj) const;
	Fixed operator*(const Fixed& obj) const;
	Fixed operator/(const Fixed& obj) const;
	Fixed operator++(int);
	Fixed operator--(int);
	Fixed& operator++();
	Fixed& operator--();

	static Fixed& min(Fixed& obj_1, Fixed& obj_2);
	static const Fixed& min(const Fixed& obj_1, const Fixed& obj_2);
	static Fixed& max(Fixed& obj_1, Fixed& obj_2);
	static const Fixed& max(const Fixed& obj_1, const Fixed& obj_2);

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
