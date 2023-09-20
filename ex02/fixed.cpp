#include "fixed.hpp"

Fixed::Fixed() {
	this->_number = 0;
}

Fixed::Fixed(int int_number) {
	this->_number = int_number * (1 << this->_number_fractional_bits);
}

Fixed::Fixed(float float_number) {
	this->_number = roundf(float_number * (1 << this->_number_fractional_bits));
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const {
	return (_number);
}

void Fixed::setRawBits(const int raw) {
	this->_number = raw;
}

int Fixed::toInt() const {
	return (this->_number / (1 << this->_number_fractional_bits));
}

float Fixed::toFloat() const {
	return ((float)this->_number / (float)(1 << this->_number_fractional_bits));
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2) {
	return (f1 >= f2 ? (f1) : (f2));
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2) {
	return (f1 >= f2 ? (f1) : (f2));
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2) {
	return (f1 <= f2 ? (f1) : (f2));
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2) {
	return (f1 <= f2 ? (f1) : (f2));
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	if (this == &fixed)
		return (*this);
	this->_number = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator > (const Fixed &other) const {return (toFloat() > other.toFloat());}
bool Fixed::operator < (const Fixed &other) const {return (toFloat() < other.toFloat());}
bool Fixed::operator <= (const Fixed &other) const {return (toFloat() <= other.toFloat());}
bool Fixed::operator >= (const Fixed &other) const {return (toFloat() >= other.toFloat());}
bool Fixed::operator == (const Fixed &other) const {return (toFloat() == other.toFloat());}
bool Fixed::operator != (const Fixed &other) const {return (toFloat() != other.toFloat());}

float Fixed::operator + (const Fixed &other) {return (toFloat() + other.toFloat());}
float Fixed::operator - (const Fixed &other) {return (toFloat() - other.toFloat());}
float Fixed::operator * (const Fixed &other) {return (toFloat() * other.toFloat());}
float Fixed::operator / (const Fixed &other) {return (toFloat() / other.toFloat());}

Fixed Fixed::operator ++ () {
	this->_number++;
	return (*this);
}

Fixed Fixed::operator ++ (int) {
	const Fixed tmp(*this);
	this->_number++;
	return (tmp);
}

Fixed Fixed::operator -- () {
	this->_number--;
	return (*this);
}

Fixed Fixed::operator -- (int) {
	const Fixed tmp(*this);
	this->_number--;
	return (tmp);
}

std::ostream& operator << (std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}