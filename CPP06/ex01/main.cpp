#include "Serializer.hpp"
#include "Data.hpp"

int main ()
{
	Data raw = {"Hello World!", "Tokyo", 42};

	uintptr_t serialized = Serializer::serialize(&raw);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << serialized << std::endl;
	std::cout << *deserialized << std::endl;

	return 0;
}
