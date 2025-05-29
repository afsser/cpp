#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"), _signMin(150), _execMin(150), _signed(false) {
	std::cout << BOLD "Form default constructor called" RST << std::endl;
}
Form::Form(std::string name, unsigned int signMin, unsigned int execMin) :
	_name(name), _signMin(signMin), _execMin(execMin), _signed(false) {
	if (signMin < 1 || execMin < 1)
		throw Form::GradeTooHighException();
	else if (signMin > 150 || execMin > 150)
		throw Form::GradeTooLowException();
	std::cout << BOLD "Form " BLU << this->_name << BOLD " created" RST << std::endl;
}
Form::~Form() {
	std::cout << BLU << this->_name << BOLD " form destructor called" RST << std::endl;
}
Form::Form(const Form &copy) :
	_name(copy._name), _signMin(copy._signMin), _execMin(copy._execMin), _signed(copy._signed) {
	std::cout << BLU "Form copy constructor called" RST << std::endl;
}
Form &Form::operator=(const Form &copy) {
	std::cout << YEL "Form copy assignment operator called" RST << std::endl;
	if (this != &copy) {
		this->_signed = copy._signed;
	}
	return *this;
}
std::string Form::getName() const {
	return (this->_name);
}
bool Form::getSigned() const {
	return (this->_signed);
}
unsigned int Form::getSignMin() const {
	return (this->_signMin);
}
unsigned int Form::getExecMin() const {
	return (this->_execMin);
}
bool Form::beSigned(const Bureaucrat &b) {
	if (this->_signed) {
		std::cout << BLU << b.getName() << RED " couldn't sign " BLU << this->_name << YEL " form:" RED " it is already signed" RST << std::endl;
		return (false);
	}
	if (b.getGrade() <= this->_signMin) {
		this->_signed = true;
		return (true);
	} else {
		throw Form::GradeTooHighException();
	}
		std::cout << BLU << b.getName() << YEL " couldn't sign " BLU << this->_name << YEL " form:" RED " unknown error" RST << std::endl;
		return (false);
}
const char* Form::GradeTooHighException::what() const throw() {
	return (RED "Form grade is too high" RST);
}
const char* Form::GradeTooLowException::what() const throw() {
	return (RED "Form grade is too low" RST);
}
std::ostream& operator<<(std::ostream& os, const Form& form) {
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
