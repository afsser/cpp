#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
#include "../colors.hpp"

ScalarConverter::ScalarConverter() {
	// Default constructor
}
ScalarConverter::~ScalarConverter() {
	// Default destructor
}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	// Default copy constructor
	*this = copy;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	// Default copy assignment
	if (this != &copy) {}
	return *this;
}

void	convertToChar(const std::string str)
{
	try {
		if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
			std::cout << "char: '" << str[0] << "'" << std::endl;
			return;
		}
		double d = std::strtod(str.c_str(), NULL);
		if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || std::isnan(d) || std::isinf(d))
			throw std::invalid_argument("Impossible");
		else if (std::isnan(d) || std::isinf(d))
			throw std::invalid_argument("Impossible");
		else if (!std::isprint(static_cast<char>(d)))
			throw std::invalid_argument("Non displayable");
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}
}
// void	convertToInt(const std::string str)
// {
// 	try {
// 		int value = std::stoi(str);
// 		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
// 			throw std::out_of_range("int overflow");
// 		std::cout << "int: " << value << std::endl;
// 	} catch (const std::invalid_argument &e) {
// 		std::cout << "int: impossible" << std::endl;
// 	} catch (const std::out_of_range &e) {
// 		std::cout << "int: overflow" << std::endl;
// 	}
// }
// void	convertToFloat(const std::string str)
// {

// }
// void	convertToDouble(const std::string str)
// {

// }

void ScalarConverter::convert(const std::string &str) {
	convertToChar(str);
	// convertToInt(str);
	// convertToFloat(str);
	// convertToDouble(str);
}