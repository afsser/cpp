#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "../Colors.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 25, 5) {
	std::cout << BOLD "RobotomyRequestForm default constructor called" RST << std::endl;
	this->_target = "default";
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 25, 5) {
	std::cout << BLU << this->_target;
	std::cout << BOLD "'s RobotomyRequestForm parameterized constructor called" RST << std::endl;
	this->_target = target;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {
		std::cout << BLU << this->_target;
	std::cout << BLU "'s RobotomyRequestForm copy constructor called" RST << std::endl;
	*this = copy;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	std::cout << BLU << this->_target;
	std::cout << YEL "'s RobotomyRequestForm copy assignment operator called" RST << std::endl;
	if (this != &copy) {
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << BLU << this->_target << BOLD "'s RobotomyRequestForm destructor called" RST << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false) {
		std::cout << RED "RobotomyRequestForm " BLU << this->_target << RED " is not signed, cannot execute" RST << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getExecMin())
		throw AForm::GradeTooLowException();
	std::cout << BLU "BLING BLIING BLIING " RST;
	if (rand() % 2)
		std::cout << BLU << this->_target << GRN " successfully robotomized!" RST << std::endl;
	else
		std::cout << BLU << this->_target << RED "'s Robotomization FAILURE" RST << std::endl;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form) {
	os << std::endl;
	os << YEL "RobotomyRequestForm targetting: " BLU << form.getTarget() << std::endl;
	os << YEL "Signed: " << (form.getSigned() ? GRN "Yes" : RED "No") << std::endl;
	os << YEL "Sign Min: " BLU << form.getSignMin() << std::endl; 
	os << YEL "Exec Min: " BLU << form.getExecMin() << std::endl;
	os << std::endl;
	return os;
}