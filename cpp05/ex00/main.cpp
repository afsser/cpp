#include "Bureaucrat.hpp"
#include "../Colors.hpp"

int main() {
	std::cout << ORG "==== BUREAUCRAT CREATION ====" RST << std::endl;
	{
		try {
			Bureaucrat foolano("Foolano", 1);
			std::cout << foolano << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;	
	std::cout << ORG "==== LOW GRADE BUREAUCRAT ====" RST << std::endl;
	{
		try {
			Bureaucrat lowGrade("Cyclano", 151);
			std::cout << lowGrade << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;	
	std::cout << ORG "==== HIGH GRADE BUREAUCRAT ====" RST << std::endl;
	{
		try {
			Bureaucrat highGrade("HighGrade", 0);
			std::cout << highGrade << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;	
	std::cout << ORG "==== OVER INCREMENT ====" RST << std::endl;
	{
		try {
			Bureaucrat foolano("Foolano", 1);
			std::cout << foolano << std::endl;
			foolano.incrementGrade();
			std::cout << foolano << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;	
	std::cout << ORG "==== UNDER INCREMENT ====" RST << std::endl;
	{
		try {
			Bureaucrat foolano("Foolano", 150);
			std::cout << foolano << std::endl;
			foolano.decrementGrade();
			std::cout << foolano << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << ORG << "==== DEFAULT BUREAUCRAT ====" RST << std::endl;
	{
		Bureaucrat foolano;
	}
	return 0;
}