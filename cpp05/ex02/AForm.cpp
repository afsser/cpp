#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "../Colors.hpp"

AForm::AForm() : _name("Form"), _signed(false), _signMin(150), _execMin(150) {
	std::cout << BOLD "Form default constructor called" RST << std::endl;
}
AForm::AForm(std::string name, unsigned int signMin, unsigned int execMin) {
	if (signMin < 1 || execMin < 1)
		throw AForm::GradeTooHighException();
	else if (signMin > 150 || execMin > 150)
		throw AForm::GradeTooLowException();
	this->_name = name;
	this->_signed = false;
	this->_signMin = signMin;
	this->_execMin = execMin;
	std::cout << BOLD "Form " BLU << this->_name << BOLD " created" RST << std::endl;
}
AForm::~AForm() {
	std::cout << BLU << this->_name << BOLD " form destructor called" RST << std::endl;
}
AForm::AForm(const AForm &copy) {
	std::cout << BLU "Form copy constructor called" RST << std::endl;
	*this = copy;
}
AForm &AForm::operator=(const AForm &copy) {
	std::cout << YEL "Form copy assignment operator called" RST << std::endl;
	if (this != &copy) {
		this->_name = copy._name;
		this->_signed = copy._signed;
		this->_signMin = copy._signMin;
		this->_execMin = copy._execMin;
	}
	return *this;
}
std::string AForm::getName() const {
	return (this->_name);
}
bool AForm::getSigned() const {
	return (this->_signed);
}
unsigned int AForm::getSignMin() const {
	return (this->_signMin);
}
unsigned int AForm::getExecMin() const {
	return (this->_execMin);
}
bool AForm::beSigned(const Bureaucrat &b) {
	if (this->_signed) {
		std::cout << BLU << b.getName() << RED " couldn't sign " BLU << this->_name << YEL " form:" RED " it is already signed" RST << std::endl;
		return (false);
	}
	if (b.getGrade() <= this->_signMin) {
		this->_signed = true;
		return (true);
	} else {
		throw AForm::GradeTooHighException();
	}
		std::cout << BLU << b.getName() << YEL " couldn't sign " BLU << this->_name << YEL " form:" RED " unknown error" RST << std::endl;
		return (false);
}
const char* AForm::GradeTooHighException::what() const throw() {
	return (RED "Form grade is too high" RST);
}
const char* AForm::GradeTooLowException::what() const throw() {
	return (RED "Form grade is too low" RST);
}
std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << std::endl;
	os << BOLD "Form: " << BLU << form.getName() << RST << std::endl;
	os << YEL "Currently " << RST;
	if (form.getSigned())
		os << GRN "signed" RST << std::endl;
	else
		os << RED "not signed" RST << std::endl;
	os << YEL "Sign grade: " BLU << form.getSignMin() << std::endl;
	os << YEL "Execute grade: " BLU << form.getExecMin() << RST << std::endl;
	return os;
}
