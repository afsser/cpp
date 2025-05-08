#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}
void Harl::_debug()
{
	std::cout << BOLD << "[ DEBUG ]" << RST << std::endl;
	std::cout << BOLD << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << RST << std::endl;
}

void Harl::_info()
{
	std::cout << BLU << "[ INFO ]" << RST << std::endl;
	std::cout << BLU << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for it!" << RST << std::endl;
}
void Harl::_warning()
{
	std::cout << GRN << "[ WARNING ]" << RST << std::endl;
	std::cout << GRN << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RST << std::endl;
}
void Harl::_error()
{
	std::cout << YEL << "[ ERROR ]" << RST << std::endl;
	std::cout << YEL << "This is unacceptable! I want to speak to the manager now." << RST << std::endl;
}
void Harl::complain(std::string level)
{
	int i;
	void (Harl::*f[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};


	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*f[i])();
			return ;
		}
		i++;
	}
	std::cout << RED << "[ I'm not programmed to respond to this level ]" << RST << std::endl;
	std::cout << RED << "Please use one of the following levels: DEBUG, INFO, WARNING, ERROR." << RST << std::endl;
	std::cout << RED << "I will now exit." << RST << std::endl;
	std::cout << RED << "Please try again." << RST << std::endl;
	std::cout << RED << "Thank you for your understanding." << RST << std::endl;
	std::cout << RED << "Have a nice day!" << RST << std::endl;
	std::cout << RED << "Goodbye!" << RST << std::endl;


}

