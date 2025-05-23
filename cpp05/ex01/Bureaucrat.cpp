#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("null"), _grade(150) {
	std::cout << BOLD "Bureaucrat default constructor called" RST << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_name = name;
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
		this->_name = copy._name;
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

void Bureaucrat::signForm(Form &form) const {
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
	return (RED "Grade is too high" RST);
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return (RED "Grade is too low" RST);
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << std::endl;
	os << BOLD "Bureaucrat: " << BLU << bureaucrat.getName() << std::endl;
	os  << YEL "Grade: " BLU << bureaucrat.getGrade() << RST;
	os << std::endl;
	return os;
}
