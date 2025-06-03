#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <string>
# include <iostream>
# include <stdint.h>


struct Data {
	int			age;
	std::string	name;
};

class Serializer {
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &copy);
public:
	static uintptr_t 	serialize(Data *ptr);
	static Data 		*deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &os, const Data &data);

#endif