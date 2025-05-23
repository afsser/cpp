#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define BOLD "\033[1;37m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;36m"
# define RST "\033[0m"

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
	std::string getName();
	unsigned int getGrade();
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

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif