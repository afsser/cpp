#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>

class Form;

class Bureaucrat {
private:
	const std::string 	_name;
	unsigned int 	_grade;
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	std::string getName() const;
	unsigned int getGrade() const;
	Bureaucrat(std::string name, unsigned int grade);

	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form &form) const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif