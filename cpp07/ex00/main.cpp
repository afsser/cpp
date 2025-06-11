#include "whatever.hpp"
#include <iostream>
#include <string>
#include "colors.hpp"

int main() {
	int a = 42;
	int b = 21;

	std::cout << YEL "Before swap: a = " GRN << a << YEL ", b = " MAG << b << std::endl;
	swap(a, b);
	std::cout << BLU "After swap: a = " MAG << a << BLU ", b = " GRN << b << std::endl;
	std::cout << std::endl;

	std::cout << BLU "min(a, b): " MAG << ::min(a, b) << std::endl;
	std::cout << YEL "max(a, b): " GRN << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::string str1 = "chaine1";
	std::string str2 = "chaine2";

	std::cout << YEL "Before swap: str1 = " GRN << str1 << YEL ", str2 = " MAG << str2 << std::endl;
	swap(str1, str2);
	std::cout << BLU "After swap: str1 = " MAG << str1 << BLU ", str2 = " GRN << str2 << std::endl;
	std::cout << std::endl;
	
	std::cout << BLU "min(a, b): : " MAG << ::min(str1, str2) << std::endl;
	std::cout << YEL "max(a, b): : " GRN << ::max(str1, str2) << std::endl;
	std::cout << RST << std::endl;

	return 0;
}