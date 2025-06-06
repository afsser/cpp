#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "../Colors.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(0));
	std::cout << ORG "==== SHRUBBERY CREATION ====" RST << std::endl;
	{
		Bureaucrat george("George", 3);
		Bureaucrat bob("Bob", 150);
		ShrubberyCreationForm shrubberyForm("cool");
		std::cout << george << std::endl;
		std::cout << shrubberyForm << std::endl;
		try {
			bob.signForm(shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.signForm(shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			bob.executeForm(shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << ORG "==== CORRECT ROBOTOMY ====" RST << std::endl;
	{
		Bureaucrat george("George", 3);
		Bureaucrat bob("Bob", 150);
		RobotomyRequestForm robotomyForm("Marvin");
		std::cout << george << std::endl;
		std::cout << robotomyForm << std::endl;
				try {
			bob.signForm(robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.signForm(robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			bob.executeForm(robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << ORG "==== CORRECT PRESIDENTIAL PARDON ====" RST << std::endl;
	{
		Bureaucrat george("George", 3);
		Bureaucrat bob("Bob", 150);
		PresidentialPardonForm pardonForm("Trillian");
		std::cout << george << std::endl;
		std::cout << pardonForm << std::endl;
				try {
			bob.signForm(pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.signForm(pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			bob.executeForm(pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

}
