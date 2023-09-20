#include "fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_number = 0;
}

Fixed::Fixed(int intNumber) {
	std::cout << "Int constructor called" << std::endl;
	this->_number = intNumber << this->_numberFractionalBits;
}

Fixed::Fixed(float floatNumber) {
	std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(floatNumber * (1 << this->_numberFractionalBits));
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	if (this == &fixed)
		return (*this);
	std::cout << "Copy assignememt operator called" << std::endl;
	this->_number = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits function member called" << std::endl;
	return (_number);
}

void Fixed::setRawBits(const int raw) {
	this->_number = raw;
}

int Fixed::toInt() const {
	return (this->_number / (1 << this->_numberFractionalBits));
}

float Fixed::toFloat() const {
	return ((float)this->_number / (float)(1 << this->_numberFractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}