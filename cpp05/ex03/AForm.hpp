#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <cstdlib>

class Bureaucrat;

class AForm {
private:
	const std::string 	_name;
	const unsigned int	_signMin;
	const unsigned int	_execMin;
	bool				_signed;
public:
	AForm();
	virtual ~AForm();
	AForm(const AForm &copy);
	AForm& operator=(const AForm &copy);
	AForm(std::string name, unsigned int signMin, unsigned int execMin);
	std::string 	getName() const;
	bool			getSigned() const;
	unsigned int 	getSignMin() const;
	unsigned int 	getExecMin() const;
	bool			beSigned(const Bureaucrat &bureaucrat);
	virtual void	execute(const Bureaucrat &executor) const = 0;
	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif