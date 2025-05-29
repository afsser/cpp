#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "../Colors.hpp"

Intern::Intern() {
	std::cout << BOLD "Intern default constructor called" RST << std::endl;
}
Intern::Intern(const Intern &copy) {
	std::cout << BOLD "Intern copy constructor called" RST << std::endl;
	*this = copy;
}
Intern &Intern::operator=(const Intern &copy) {
	std::cout << BOLD "Intern copy assignment operator called" RST << std::endl;
	if (this != &copy) {}
	return *this;
}
Intern::~Intern() {
	std::cout << BOLD "Intern destructor called" RST << std::endl;
}

AForm *makeRobotomyRequestForm(const std::string &target) {
	return (new RobotomyRequestForm(target));
}
AForm *makePresidentialPardonForm(const std::string &target) {
	return (new PresidentialPardonForm(target));
}
AForm *makeShrubberyCreationForm(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	std::cout << YEL "Intern is trying to create a " << BLU << formName << YEL <<" form" << RST << std::endl;
	std::string names[3] = {
		"Robotomy Request",
		"Presidential Pardon",
		"Shrubbery Creation"
	};
	AForm *(*formCreators[3])(const std::string &) = {
		makeRobotomyRequestForm,
		makePresidentialPardonForm,
		makeShrubberyCreationForm
	};
	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			if (target.empty()) {
				std::cout << RED "Warning: Target is empty, using default value" RST << std::endl;
				return formCreators[i]("default");
			}
			return formCreators[i](target);
		}
	}
	std::cout << BLU << formName << RED << ":" << RST << std::endl;
	throw Intern::UnknownFormException();

}
const char *Intern::UnknownFormException::what() const throw() {
	return RED "Unknown form type" RST;
}
