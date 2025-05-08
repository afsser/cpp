#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	this->f[0] = &Harl::_debug;
	this->f[1] = &Harl::_info;
	this->f[2] = &Harl::_warning;
	this->f[3] = &Harl::_error;
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
}
Harl::~Harl() {}

void Harl::_debug()
{
	std::cout << GRN << "[ DEBUG ]" << RST << std::endl;
	std::cout << GRN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << RST << std::endl;
}

void Harl::_info()
{
	std::cout << GRN << "[ INFO ]" << RST << std::endl;
	std::cout << GRN << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for it!" << RST << std::endl;
}
void Harl::_warning()
{
	std::cout << GRN << "[ WARNING ]" << RST << std::endl;
	std::cout << GRN << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RST << std::endl;
}
void Harl::_error()
{
	std::cout << GRN << "[ ERROR ]" << RST << std::endl;
	std::cout << GRN << "This is unacceptable! I want to speak to the manager now." << RST << std::endl;
}
void Harl::complain(std::string level)
{
	int i;

	i = 0;
	while (i < 4 && this->levels[i] != level)
		i++;
	switch(i)
	{
		case 0:
			(this->*f[0])();
		case 1:
			(this->*f[1])();
		case 2:
			(this->*f[2])();
		case 3:
			(this->*f[3])();
			break ;
		default:
			std::cout << RED << "[ I'm not programmed to respond to this level ]" << RST << std::endl;
			std::cout << RED << "Please use one of the following levels: DEBUG, INFO, WARNING, ERROR." << RST << std::endl;
			std::cout << RED << "I will now exit." << RST << std::endl;
			std::cout << RED << "Please try again." << RST << std::endl;
			std::cout << RED << "Thank you for your understanding." << RST << std::endl;
			std::cout << RED << "Have a nice day!" << RST << std::endl;
			std::cout << RED << "Goodbye!" << RST << std::endl;
			return ;
	}

}