#include "Bureaucrat.hpp"

int main() {
	Bureaucrat foolano("Foolano", 1);
	std::cout << foolano << std::endl;
	Bureaucrat cyclano("Cyclano", 150);
	std::cout << cyclano << std::endl;
	// Bureaucrat wrongoolano("Wrongoolano", 151);
	// Bureaucrat wrongoolano2("Wrongoolano2", 0);
	try {
		foolano.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << foolano << std::endl;
	try {
		cyclano.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << cyclano << std::endl;
	try {
		foolano.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << foolano << std::endl;
	try {
		cyclano.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << cyclano << std::endl;
	return 0;
}