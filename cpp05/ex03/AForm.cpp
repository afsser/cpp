#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "../Colors.hpp"

AForm::AForm() : _name("Form"), _signMin(150), _execMin(150), _signed(false) {
	std::cout << BOLD "Form abstract default constructor called" RST << std::endl;
}
AForm::AForm(std::string name, unsigned int signMin, unsigned int execMin) :
	_name(name), _signMin(signMin), _execMin(execMin) {
	if (signMin < 1 || execMin < 1)
		throw AForm::GradeTooHighException();
	else if (signMin > 150 || execMin > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
	std::cout << BLU << this->_name << YEL " abstract" BOLD " constructor called" RST << std::endl;
}
AForm::~AForm() {
	std::cout << BLU << this->_name << BOLD " form" YEL " abstract" BOLD " destructor called" RST << std::endl;
}
AForm::AForm(const AForm &copy) : _name(copy._name), _signMin(copy._signMin), _execMin(copy._execMin), _signed(copy._signed) {
	std::cout << BLU "Form" YEL " abstract" BOLD " copy constructor called" RST << std::endl;
}
AForm &AForm::operator=(const AForm &copy) {
	std::cout << YEL "Form" YEL " abstract" BOLD " copy assignment operator called" RST << std::endl;
	if (this != &copy) {
		this->_signed = copy._signed;
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
		throw Bureaucrat::GradeTooLowException();
		return (false);
	}
}
const char* AForm::GradeTooHighException::what() const throw() {
	return (RED "Form grade is too high" RST);
}
const char* AForm::GradeTooLowException::what() const throw() {
	return (RED "Form grade is too low" RST);
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << std::endl;
	os << YEL "Form name: " BLU << form.getName() << std::endl;
	os << YEL "Signed: " << (form.getSigned() ? GRN "Yes" : RED "No") << std::endl;
	os << YEL "Sign Min: " BLU << form.getSignMin() << std::endl; 
	os << YEL "Exec Min: " BLU << form.getExecMin() << std::endl;
	os << std::endl;
	return os;
}
