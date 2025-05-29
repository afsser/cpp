#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	static const int _signGrade = 145;
	static const int _execGrade = 137;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();
	void	execute(const Bureaucrat &executor) const;
	const std::string &getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form);

#endif