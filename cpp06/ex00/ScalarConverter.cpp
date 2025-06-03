#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <cstdlib>

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
			throw std::invalid_argument("impossible");
		else if (str.empty() || std::isnan(d) || std::isinf(d))
			throw std::invalid_argument("impossible");
		else if (!std::isprint(static_cast<char>(d)))
			throw std::invalid_argument("Non displayable");
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}
}
void	convertToInt(const std::string str)
{
	try {
		if (str.length() == 1 && std::isalpha(str[0])) {
			std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
			return;
		}
		size_t i = 0;
		i = str.find_first_of("+-", i) == std::string::npos ? 0 : i + 1;
		for (; i < str.length(); ++i) {
			if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f') {
				throw std::invalid_argument("impossible");
			}
		}
		double value = std::strtod(str.c_str(), NULL);
		if (str.empty() || std::isnan(value) || std::isinf(value))
			throw std::invalid_argument("impossible");
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			throw std::invalid_argument("impossible");
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}
}
void	convertToFloat(const std::string str)
{
	try {
		if (str.length() == 1 && std::isalpha(str[0])) {
			std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
			return;
		}
		double value = std::strtod(str.c_str(), NULL);
		if (str.empty())
			throw std::invalid_argument("impossible");
		else if (std::isnan(value) || std::isinf(value)) {
			std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
			return;
		}
		size_t i = 0;
		i = str.find_first_of("+-", i) == std::string::npos ? 0 : i + 1;
		for (; i < str.length(); ++i) {
			if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f') {
				throw std::invalid_argument("impossible");
			}
		}
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			throw std::invalid_argument("impossible");
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}
}

void	convertToDouble(const std::string str)
{
	try {
		if (str.length() == 1 && std::isalpha(str[0])) {
			std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
			return;
		}
		double value = std::strtod(str.c_str(), NULL);
		if (str.empty())
			throw std::invalid_argument("impossible");
		else if (std::isnan(value) || std::isinf(value)) {
			std::cout << "double: " << static_cast<double>(value) << std::endl;
			return;
		}
		size_t i = 0;
		i = str.find_first_of("+-", i) == std::string::npos ? 0 : i + 1;
		for (; i < str.length(); ++i) {
			if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f') {
				throw std::invalid_argument("impossible");
			}
		}
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			throw std::invalid_argument("impossible");
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

void ScalarConverter::convert(const std::string &str) {
	convertToChar(str);
	convertToInt(str);
	convertToFloat(str);
	convertToDouble(str);
}