#include "ScalarConverter.hpp"
#include "../colors.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << RED "Usage: " YEL "./scalar_converter <value>" RST << std::endl;
		return (1);
	}
	try {
		ScalarConverter::convert(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
