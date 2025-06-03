#include "Serializer.hpp"
#include "../colors.hpp"

int main() {
	Data data;
	Data *deserializedData;
	data.age = 30;
	data.name = "John Doe";

	std::cout << YEL "Original Data: " RST << data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	deserializedData = Serializer::deserialize(raw);

	std::cout << BLU "Deserialized Data: " RST << *deserializedData << std::endl;

	return 0;
}