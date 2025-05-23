#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "../Colors.hpp"

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>

class Bureaucrat {
private:
	std::string 	_name;
	unsigned int 	_grade;
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	std::string getName() const;
	unsigned int getGrade() const;
	Bureaucrat(std::string name, unsigned int grade);

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif