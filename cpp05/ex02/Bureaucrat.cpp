#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "../Colors.hpp"

Bureaucrat::Bureaucrat() : _name("null"), _grade(150) {
	std::cout << BOLD "Bureaucrat default constructor called" RST << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << BOLD "Bureaucrat " BLU << this->_name << BOLD " created" RST << std::endl;
}

Bureaucrat::~Bureaucrat() {
	if (this->_name == "null")
		std::cout << BOLD "Default bureaucrat destructor called" RST << std::endl;
	else
		std::cout << BLU << this->_name << BOLD " bureaucrat destructor called" RST << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	std::cout << BLU "Bureaucrat copy constructor called" RST << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& copy) {
	std::cout << YEL "Bureaucrat copy assignment operator called" RST << std::endl;
	if (this != &copy) {
		this->_grade = copy._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

unsigned int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::signForm(AForm &form) const {
	std::cout << YEL "Bureaucrat " BLU << this->_name << YEL " is trying to sign " BLU << form.getName() << RST << std::endl;
	if (form.beSigned(*this))
		std::cout << BLU << this->_name << GRN " signed " BLU << form.getName() << RST << std::endl;	
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << YEL "Bureaucrat " BLU << this->_name << YEL "'s grade incremented" RST << std::endl;
}
void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << YEL "Bureaucrat " BLU << this->_name << YEL "'s grade decremented" RST << std::endl;
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return (RED "Bureaucrat grade is too high" RST);
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return (RED "Bureaucrat grade is too low" RST);
}
const char* Bureaucrat::FormNotSignedException::what() const throw() {
	return (RED "Bureaucrat cannot execute form: it is not signed" RST);
}
void Bureaucrat::executeForm(const AForm &form) const {
	try {
		std::cout << BLU << this->_name << YEL " is trying to execute " BLU << form.getName() << RST << std::endl;
		form.execute(*this);
		std::cout << BLU << form.getName() << GRN " executed " << RST << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << std::endl;
	os << YEL "Bureaucrat: " << BLU << bureaucrat.getName() << std::endl;
	os  << YEL "Grade: " BLU << bureaucrat.getGrade() << RST;
	os << std::endl;
	return os;
}
