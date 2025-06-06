#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "../Colors.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5),
	_target("default")
{
	std::cout << BOLD "PresidentialPardonForm default constructor called" RST << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	std::cout << BLU << this->_target;
	std::cout << BOLD "'s PresidentialPardonForm parameterized constructor called" RST << std::endl;
	this->_target = target;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {
	std::cout << BLU << this->_target;
	std::cout << BLU "'s PresidentialPardonForm copy constructor called" RST << std::endl;
	*this = copy;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	std::cout << BLU << this->_target;
	std::cout << YEL "'s PresidentialPardonForm copy assignment operator called" RST << std::endl;
	if (this != &copy) {
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << BLU << this->_target << BOLD "'s PresidentialPardonForm destructor called" RST << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false) 
		throw Bureaucrat::FormNotSignedException();
	if (executor.getGrade() > this->getExecMin())
		throw Bureaucrat::GradeTooLowException();
	std::cout << MAG "Zaphod Beeblebrox" GRN " granted a Presidential Pardon to " BLU << this->_target << RST << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form) {
	os << std::endl;
	os << YEL "PresidentialPardonForm targetting " BLU << form.getTarget() << std::endl;
	os << YEL "Signed: " << (form.getSigned() ? GRN "Yes" : RED "No") << std::endl;
	os << YEL "Sign Min: " BLU << form.getSignMin() << std::endl; 
	os << YEL "Exec Min: " BLU << form.getExecMin() << std::endl;
	os << std::endl;
	return os;
}