#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nbContacts(0), _index(0)
{
	std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destroyed" << std::endl;
}

bool isNumeric(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

void PhoneBook::addContact(void)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);

	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);

	bool isValid = false;
	while (!isValid)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);
		if (!isNumeric(phoneNumber))
		{
			std::cout << "Error: Phone number must be numeric." << std::endl;
		}
		else
			isValid = true;
	}

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Error: A contact cannot have empty fields." << std::endl;
		return;
	}

	_contacts[_index].setFirstName(firstName);
	_contacts[_index].setLastName(lastName);
	_contacts[_index].setNickname(nickname);
	_contacts[_index].setPhoneNumber(phoneNumber);
	_contacts[_index].setDarkestSecret(darkestSecret);

	_index = (_index + 1) % 8;

	if (_nbContacts < 8)
		_nbContacts++;

	std::cout << "Contact added successfully!" << std::endl;
}

void displayContact(int index, Contact contact_list[8])
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "First Name: " << contact_list[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contact_list[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contact_list[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contact_list[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact_list[index].getDarkestSecret() << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}


void PhoneBook::searchContact(void)
{
	if (_nbContacts == 0)
	{
		std::cout << "No contacts found." << std::endl;
		return;
	}
	

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|    Index | 1st Name | LastName | Nickname |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < _nbContacts; i++)
	{
		std::cout << "| " << std::setw(8) << i << " |";
		std::cout << std::setw(10) << (_contacts[i].getFirstName().length() > 10 ? _contacts[i].getFirstName().substr(0, 9) + "." : _contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << (_contacts[i].getLastName().length() > 10 ? _contacts[i].getLastName().substr(0, 9) + "." : _contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << (_contacts[i].getNickname().length() > 10 ? _contacts[i].getNickname().substr(0, 9) + "." : _contacts[i].getNickname()) << "|" << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;

	int index;
	int isValidIndex = false;
	while (!isValidIndex)
	{
		std::cout << "Enter the index of the contact you want to view: ";
		std::cin >> index;
		if (std::cin.fail() || index < 0 || index >= _nbContacts)

		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please type a valid index." << std::endl;
		}
		else
			isValidIndex = true;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	displayContact(index, _contacts);

}
