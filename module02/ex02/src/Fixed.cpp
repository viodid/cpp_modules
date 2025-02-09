#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

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

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
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


// OPERATORS OVERLOAD
std::ostream& operator<<(std::ostream& outputStream, const Fixed& obj)
{
	outputStream << obj.toFloat();
	return (outputStream);
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = obj.getRawBits();
	return *this;
}


bool Fixed::operator>(const Fixed& obj) const { return _value > obj.getRawBits(); }

bool Fixed::operator<(const Fixed& obj) const { return _value < obj.getRawBits(); }

bool Fixed::operator>=(const Fixed& obj) const { return _value >= obj.getRawBits(); }

bool Fixed::operator<=(const Fixed& obj) const { return _value <= obj.getRawBits(); }

bool Fixed::operator==(const Fixed& obj) const { return _value == obj.getRawBits(); }

bool Fixed::operator!=(const Fixed& obj) const { return _value != obj.getRawBits(); }

Fixed Fixed::operator+(const Fixed& obj) const
{
	const int fix_sum_val = _value + obj.getRawBits();
	return (Fixed(fix_sum_val));
}

Fixed Fixed::operator-(const Fixed& obj) const
{
	const int fix_sum_val = abs(_value - obj.getRawBits());
	return (Fixed(fix_sum_val));
}

Fixed Fixed::operator*(const Fixed& obj) const
{
	const float fix_sum_val = static_cast<float>(_value * obj.getRawBits());
	return (Fixed(fix_sum_val / (256 * 256)));
}

Fixed Fixed::operator/(const Fixed& obj) const
{
	if (obj.getRawBits() == 0)
		return (Fixed());
	const int fix_sum_val = abs(_value / obj.getRawBits());
	return (Fixed(fix_sum_val));
}

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

