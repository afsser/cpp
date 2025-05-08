#include "Fixed.hpp"


int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(b);
	std::cout << "a = " << a << std::endl;
	for (int i = 0; i < 256; i++)
		++a;
	std::cout << "a = " << a << std::endl;
	a = 0;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "max a/b = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min a/b = " << Fixed::min( a, b ) << std::endl;
	std::cout << "&max a/b = " << &Fixed::max( a, b ) << std::endl;
	std::cout << "&min a/b = " << &Fixed::min( a, b ) << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "++a = " << (c / Fixed(2)) << std::endl;
	return 0;
}