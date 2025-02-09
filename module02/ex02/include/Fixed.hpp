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
	// Fixed& operator++(const Fixed& obj); // TODO: implement
	// Fixed& operator--(const Fixed& obj);

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
float calculate_double_fixed(float value);
#endif
