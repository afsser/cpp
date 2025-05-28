#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "../Colors.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 25, 5) {
	std::cout << BOLD "ShrubberyCreationForm default constructor called" RST << std::endl;
	this->_target = "default";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 25, 5) {
	std::cout << BLU << this->_target;
	std::cout << BOLD "'s ShrubberyCreationForm parameterized constructor called" RST << std::endl;
	this->_target = target;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
		std::cout << BLU << this->_target;
	std::cout << BLU "'s ShrubberyCreationForm copy constructor called" RST << std::endl;
	*this = copy;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	std::cout << BLU << this->_target;
	std::cout << YEL "'s ShrubberyCreationForm copy assignment operator called" RST << std::endl;
	if (this != &copy) {
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << BLU << this->_target << BOLD "'s ShrubberyCreationForm destructor called" RST << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

static void createShrubbery(const std::string &target) {
	std::ofstream ofs(target + "_shrubbery");
	if (!ofs.is_open()) {
		std::cerr << RED "Error: Could not open file " << target + "_shrubbery" << RST << std::endl;
		return;
	}
	ofs << "                                                     . \n";
    ofs << "                                      .         ;      \n";
    ofs << "         .              .              ;%     ;;       \n";
    ofs << "           ,           ,                :;%  %;        \n";
    ofs << "            :         ;                   :;%;'     ., \n";
    ofs << "   ,.        %;     %;            ;        %;'    ,;   \n";
    ofs << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'    \n";
    ofs << "      %;       %;%;      ,  ;       %;  ;%;   ,%;'     \n";
    ofs << "       ;%;      %;        ;%;        % ;%;  ,%;'       \n";
    ofs << "        `%;.     ;%;     %;'         `;%%;.%;'         \n";
    ofs << "         `:;%.    ;%%. %@;        %; ;@%;%'            \n";
    ofs << "            `:%;.  :;bd%;          %;@%;'              \n";
    ofs << "              `@%:.  :;%.         ;@@%;'               \n";
    ofs << "                `@%.  `;@%.      ;@@%;                 \n";
    ofs << "                  `@%%. `@%%    ;@@%;                  \n";
    ofs << "                    ;@%. :@%%  %@@%;                   \n";
    ofs << "                      %@bd%%%bd%%:;                    \n";
    ofs << "                        #@%%%%%:;;                     \n";
    ofs << "                        %@@%%%::;                      \n";
    ofs << "                        %@@@%(o);  . '                 \n";
    ofs << "                        %@@@o%;:(.,'                   \n";
    ofs << "                    `.. %@@@o%::;                      \n";
    ofs << "                       `)@@@o%::;                      \n";
    ofs << "                        %@@(o)::;                      \n";
    ofs << "                       .%@@@@%::;                      \n";
    ofs << "                       ;%@@@@%::;.                     \n";
    ofs << "                      ;%@@@@%%:;;;.                    \n";
    ofs << "                  ...;%@@@@@%%:;;;;,..                 \n";

	ofs.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false) {
		std::cout << RED "ShrubberyCreationForm " BLU << this->_target << RED " is not signed, cannot execute" RST << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getExecMin())
		throw AForm::GradeTooLowException();
	std::cout << GRN "Presidential pardon granted to " BLU << this->_target << RST << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form) {
	os << std::endl;
	os << YEL "ShrubberyCreationForm targetting " BLU << form.getTarget() << std::endl;
	os << YEL "Signed: " << (form.getSigned() ? GRN "Yes" : RED "No") << std::endl;
	os << YEL "Sign Min: " BLU << form.getSignMin() << std::endl; 
	os << YEL "Exec Min: " BLU << form.getExecMin() << std::endl;
	os << std::endl;
	return os;
}