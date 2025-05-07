#ifndef MEGAPHONE_HPP
#define MEGAPHONE_HPP

#include <iostream>
#include <string>

class Megaphone {
public:
	Megaphone();
	~Megaphone();
	void shout(const std::string &message) const;
};

#endif