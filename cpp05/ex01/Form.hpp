#ifndef FORM_HPP
# define FORM_HPP

# include "../Colors.hpp"
# include <iostream>
# include <string>
# include <cstdlib>

class Bureaucrat;

class Form {
private:
	std::string 	_name;
	bool			_signed;
	unsigned int	_signMin;
	unsigned int	_execMin;
public:
	Form();
	~Form();
	Form(const Form &copy);
	Form& operator=(const Form &copy);
	Form(std::string name, unsigned int signMin, unsigned int execMin);
	std::string 	getName() const;
	bool			getSigned() const;
	unsigned int 	getSignMin() const;
	unsigned int 	getExecMin() const;
	bool			beSigned(const Bureaucrat &bureaucrat);
	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream& os, const Form& form);

#endif