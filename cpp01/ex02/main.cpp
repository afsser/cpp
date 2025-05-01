#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";	
	std::string* ptr = &str;
	std::string& ref = str;
	std::cout << "String address: " << &str << std::endl;
	std::cout << "Pointer address: " << ptr << std::endl;
	std::cout << "Reference address: " << &ref << std::endl;
	std::cout << "String value: " << str << std::endl;
	std::cout << "Pointer value: " << *ptr << std::endl;
	std::cout << "Reference value: " << ref << std::endl;

	ref = "NEW STRING";

	std::cout << "\nAfter changing the string:\n" << std::endl;


	std::cout << "String address: " << &str << std::endl;
	std::cout << "Pointer address: " << ptr << std::endl;
	std::cout << "Reference address: " << &ref << std::endl;
	std::cout << "String value: " << str << std::endl;
	std::cout << "Pointer value: " << *ptr << std::endl;
	std::cout << "Reference value: " << ref << std::endl;
	return (0);
}