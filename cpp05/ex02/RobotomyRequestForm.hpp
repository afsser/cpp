#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	static const int _signGrade = 72;
	static const int _execGrade = 45;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();
	void	execute(const Bureaucrat &executor) const;
	const std::string &getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form);

#endif