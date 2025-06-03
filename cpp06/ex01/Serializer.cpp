#include "Serializer.hpp"
#include "../colors.hpp"

Serializer::Serializer() {
	// Default constructor
}
Serializer::~Serializer() {
	// Default destructor
}
Serializer::Serializer(const Serializer &copy) {
	// Default copy constructor
	*this = copy;
}
Serializer &Serializer::operator=(const Serializer &copy) {
	// Default copy assignment
	if (this != &copy) {}
	return *this;
}
uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}
Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
std::ostream &operator<<(std::ostream &os, const Data &data) {
	os << std::endl << GRN "{" << std::endl;
	os << "		age: " ORG "\"" << data.age << "," << std::endl;
	os << GRN "		name: " ORG "\"" << data.name << "\" "<< std::endl;
	os << GRN "}" RST << std::endl;
	return os;
}
