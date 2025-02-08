#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fracBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	const int intPart = static_cast<int>(f);
	const float floatPart = f - intPart;
	const int fixFractPart = static_cast<int>(roundf(floatPart * 256));
	_value = (intPart << 8) + fixFractPart;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return _value;
}

void Fixed::setRawBits(int raw) {(void)raw;}

float Fixed::toFloat() const
{
	return (static_cast<float>(_value) / 256);
}

int Fixed::toInt() const
{
	return (_value >> _fracBits);
}

std::ostream& operator<<(std::ostream& outputStream, const Fixed& obj)
{
	outputStream << obj.toFloat();
	return (outputStream);
}

