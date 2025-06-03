#include "Base.hpp"
#include "../colors.hpp"
#include <iostream>

Base *generate(void) {
	srand(static_cast<unsigned int>(time(0)));
	int random = rand() % 3;
	if (random == 0) {
		std::cout << BLU "Generated type:" MAG " A" RST << std::endl;
		return new A();
	} else if (random == 1) {
		std::cout << BLU "Generated type:" MAG " B" RST << std::endl;
		return new B();
	} else {
		std::cout << BLU "Generated type:" MAG " C" RST << std::endl;
		return new C();
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << BLU "Type: " MAG "A" RST << std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout << BLU "Type: " MAG "B" RST << std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout << BLU "Type: " MAG "C" RST << std::endl;
	} else {
		std::cout << RED "Unknown type" RST << std::endl;
	}
}

void identify(Base &p) {
	std::string type = "unknown";
	try {
		(void)dynamic_cast<A &>(p);
		type = "A";
	} catch (std::exception &) {}

	try {
		(void)dynamic_cast<B &>(p);
		type = "B";
	} catch (std::exception &) {}

	try {
		(void)dynamic_cast<C &>(p);
		type = "C";
	} catch (std::exception &) {}

	if (type == "unknown") {
		std::cout << RED "Unknown type" RST << std::endl;
		return;
	}
	std::cout << BLU "Type: " MAG << type << RST << std::endl;
}