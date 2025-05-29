#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"

# include <string>
class Intern {
public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	~Intern();
	AForm *makeForm(const std::string &formName, const std::string &target);
	class UnknownFormException : public std::exception {
	public:
		const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &os, const Intern &intern);

#endif