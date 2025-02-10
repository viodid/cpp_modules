#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0) { }

Fixed::~Fixed() { }

Fixed::Fixed(const int n) { _value = n << _fracBits; }

Fixed::Fixed(const float f)
{
	const int intPart = static_cast<int>(f);
	const float floatPart = f - intPart;
	const int fixFractPart = static_cast<int>(roundf(floatPart * 256));
	_value = (intPart << 8) + fixFractPart;
}

Fixed::Fixed(const Fixed& obj) { *this = obj; }

int Fixed::getRawBits() const { return _value; }

void Fixed::setRawBits(const int raw) {this->_value = raw;}

float Fixed::toFloat() const { return (static_cast<float>(_value) / 256); }

int Fixed::toInt() const { return (_value >> _fracBits); }

Fixed& Fixed::min(Fixed& obj_1, Fixed& obj_2)
{
	if (obj_1 < obj_2)
		return obj_1;
	return obj_2;
}

const Fixed& Fixed::min(const Fixed& obj_1, const Fixed& obj_2)
{
	if (obj_1 < obj_2)
		return obj_1;
	return obj_2;
}

Fixed& Fixed::max(Fixed& obj_1, Fixed& obj_2)
{
	if (obj_1 > obj_2)
		return obj_1;
	return obj_2;
}

const Fixed& Fixed::max(const Fixed& obj_1, const Fixed& obj_2)
{
	if (obj_1 > obj_2)
		return obj_1;
	return obj_2;
}

// OPERATORS OVERLOAD
std::ostream& operator<<(std::ostream& outputStream, const Fixed& obj)
{
	outputStream << obj.toFloat();
	return (outputStream);
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	this->_value = obj.getRawBits();
	return *this;
}


bool Fixed::operator>(const Fixed& obj) const { return _value > obj.getRawBits(); }

bool Fixed::operator<(const Fixed& obj) const { return _value < obj.getRawBits(); }

bool Fixed::operator>=(const Fixed& obj) const { return _value >= obj.getRawBits(); }

bool Fixed::operator<=(const Fixed& obj) const { return _value <= obj.getRawBits(); }

bool Fixed::operator==(const Fixed& obj) const { return _value == obj.getRawBits(); }

bool Fixed::operator!=(const Fixed& obj) const { return _value != obj.getRawBits(); }

Fixed Fixed::operator+(const Fixed& obj) const { return (Fixed(this->toFloat() + obj.toFloat())); }

Fixed Fixed::operator-(const Fixed& obj) const { return (Fixed(this->toFloat() - obj.toFloat())); }

Fixed Fixed::operator*(const Fixed& obj) const { return (Fixed(this->toFloat() * obj.toFloat())); }

Fixed Fixed::operator/(const Fixed& obj) const
{
	if (obj.getRawBits() == 0)
		return (Fixed());
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed Fixed::operator++(int) { return Fixed(static_cast<float>(this->_value++) / 256); }

Fixed Fixed::operator--(int) { return Fixed(static_cast<float>(this->_value--) / 256); }

Fixed& Fixed::operator++() { this->setRawBits(this->getRawBits() + 1); return *this; }

Fixed& Fixed::operator--() { this->setRawBits(this->getRawBits() - 1); return *this; }
