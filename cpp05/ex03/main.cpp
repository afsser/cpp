#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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
		Intern stag;
		AForm *shrubberyForm;
		shrubberyForm = stag.makeForm("Shrubbery Creation", "cool");
		if (!shrubberyForm) {
			std::cerr << RED "Failed to create ShrubberyCreationForm" RST << std::endl;
			return 1;
		}
		std::cout << george << std::endl;
		std::cout << *shrubberyForm << std::endl;
		try {
			bob.signForm(*shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(*shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.signForm(*shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			bob.executeForm(*shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(*shrubberyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		if (shrubberyForm) {
			delete shrubberyForm;
			shrubberyForm = NULL;
		}
	}
	std::cout << std::endl;
	std::cout << ORG "==== CORRECT ROBOTOMY ====" RST << std::endl;
	{
		Bureaucrat george("George", 3);
		Bureaucrat bob("Bob", 150);
		Intern stag;
		AForm *robotomyForm;
		robotomyForm = stag.makeForm("Robotomy Request", "Marvin");
		if (!robotomyForm) {
			std::cerr << RED "Failed to create RobotomyRequestForm" RST << std::endl;
			return 1;
		}
		std::cout << george << std::endl;
		std::cout << *robotomyForm << std::endl;
				try {
			bob.signForm(*robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(*robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.signForm(*robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			bob.executeForm(*robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(*robotomyForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		if (robotomyForm) {
			delete robotomyForm;
			robotomyForm = NULL;
		}
	}
	std::cout << std::endl;
	std::cout << ORG "==== CORRECT PRESIDENTIAL PARDON ====" RST << std::endl;
	{
		Bureaucrat george("George", 3);
		Bureaucrat bob("Bob", 150);
		Intern stag;
		AForm *pardonForm;
		pardonForm = stag.makeForm("Presidential Pardon", "Trillian");
		if (!pardonForm) {
			std::cerr << RED "Failed to create PresidentialPardonForm" RST << std::endl;
			return 1;
		}
		std::cout << george << std::endl;
		std::cout << *pardonForm << std::endl;
				try {
			bob.signForm(*pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(*pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.signForm(*pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			bob.executeForm(*pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.executeForm(*pardonForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		if (pardonForm) {
			delete pardonForm;
			pardonForm = NULL;
		}
	}
	std::cout << std::endl;
	std::cout << ORG "==== UNKNOWN FORM ====" RST << std::endl;
	{
		Intern stag;
		try {
			AForm *unknownForm = stag.makeForm("Unknown Form", "Target");
			if (unknownForm) {
				delete unknownForm;
				unknownForm = NULL;
			}
		} catch (const Intern::UnknownFormException &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
