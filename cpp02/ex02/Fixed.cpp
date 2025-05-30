#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedPointValue(0) {
};
Fixed::Fixed(const Fixed &copy) : _fixedPointValue(copy._fixedPointValue) {
};
Fixed& Fixed::operator=(const Fixed &copy) {
	if (this != &copy) {
		this->_fixedPointValue = copy.getRawBits();
	}
	return *this;
};
Fixed::~Fixed() {
};

Fixed::Fixed(const int value) {
	this->_fixedPointValue = value << _fractionalBits;
};
Fixed::Fixed(const float value) {
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed &Fixed::operator+(const Fixed &copy) {
	_fixedPointValue += copy.getRawBits();
	return *this;
}
Fixed &Fixed::operator-(const Fixed &copy) {
	_fixedPointValue -= copy.getRawBits();
	return *this;
}
Fixed &Fixed::operator*(const Fixed &copy) {
	_fixedPointValue = (_fixedPointValue * copy.getRawBits()) >> _fractionalBits;
	return *this;
}
Fixed &Fixed::operator/(const Fixed &copy) {
	if (copy.getRawBits() == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return *this;
	}
	_fixedPointValue = (_fixedPointValue << _fractionalBits) / copy.getRawBits();
	return *this;
}

Fixed &Fixed::operator++(void) {
	_fixedPointValue++;
	return *this;
}
Fixed &Fixed::operator--(void) {
	_fixedPointValue--;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	_fixedPointValue++;
	return temp;
}
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	_fixedPointValue--;
	return temp;
}

bool Fixed::operator>(const Fixed &copy) const {
	return this->_fixedPointValue > copy.getRawBits();
}
bool Fixed::operator<(const Fixed &copy) const {
	return this->_fixedPointValue < copy.getRawBits();
}
bool Fixed::operator>=(const Fixed &copy) const {
	return this->_fixedPointValue >= copy.getRawBits();
}
bool Fixed::operator<=(const Fixed &copy) const {
	return this->_fixedPointValue <= copy.getRawBits();
}
bool Fixed::operator==(const Fixed &copy) const {
	return this->_fixedPointValue == copy.getRawBits();
}
bool Fixed::operator!=(const Fixed &copy) const {
	return this->_fixedPointValue != copy.getRawBits();
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

int Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
};
void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
};

float Fixed::toFloat(void)const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}
int Fixed::toInt(void)const {
	return this->_fixedPointValue >> _fractionalBits;
}