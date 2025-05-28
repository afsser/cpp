#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << ORG "==== FORM CREATION ====" RST << std::endl;
	{
		try {
			Form bribeForm("Bribe", 1, 1);
			std::cout << bribeForm << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;	
	std::cout << ORG "==== LOW GRADE FORM ====" RST << std::endl;
	{
		try {
			Form lowGradeForm("LowGrade", 151, 151);
			std::cout << lowGradeForm << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;	
	std::cout << ORG "==== HIGH GRADE FORM ====" RST << std::endl;
	{
		try {
			Form highGradeForm("HighGrade", 0, 0);
			std::cout << highGradeForm << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;	
	std::cout << ORG "==== BUREAUCRAT SIGNING FORM ====" RST << std::endl;
	{
		Bureaucrat foolano("Foolano", 1);
		std::cout << foolano << std::endl;
		Bureaucrat cyclano("Cyclano", 10);
		std::cout << cyclano << std::endl;
		Form bribeForm("Bribe", 12, 12);
		std::cout << bribeForm << std::endl;
		try {
			foolano.signForm(bribeForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << bribeForm << std::endl;
		try {
			cyclano.signForm(bribeForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;	
	std::cout << ORG "==== LOW GRADE BUREAUCRAT CAN'T SIGN FORM ====" RST << std::endl;
	{
		Bureaucrat noob("Noob", 150);
		std::cout << noob << std::endl;
		Form bribeForm("Bribe", 12, 12);
		std::cout << bribeForm << std::endl;
		try {
			noob.signForm(bribeForm);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}