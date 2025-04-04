#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else if (command == "")
			continue;
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}