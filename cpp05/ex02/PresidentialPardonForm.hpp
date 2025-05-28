#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	// static const int _signGrade = 25;
	// static const int _execGrade = 5;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();
	void	execute(const Bureaucrat &executor) const;
	const std::string &getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

# endif