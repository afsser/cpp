#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>


class Fixed
{
	private:
		int                 _fixedPointValue;
		static const int    _fractionalBits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		Fixed &operator+(const Fixed &copy);
		Fixed &operator-(const Fixed &copy);
		Fixed &operator/(const Fixed &copy);
		Fixed &operator*(const Fixed &copy);
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		bool operator>(const Fixed &copy) const;
		bool operator<(const Fixed &copy) const;
		bool operator>=(const Fixed &copy) const;
		bool operator<=(const Fixed &copy) const;
		bool operator==(const Fixed &copy) const;
		bool operator!=(const Fixed &copy) const;
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif