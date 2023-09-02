#include "Serializer.hpp"
#include "Data.hpp"

int main ()
{
	Data raw = {"Hello World!", "Tokyo", 42};

	uintptr_t serialized = Serializer::serialize(&raw);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << serialized << std::endl;
	std::cout << *deserialized << std::endl;

	int	i0 = 42;

	std::bitset<32> bits1(static_cast<unsigned long>(i0));
	std::cout << "Int as bits: " << bits1 << std::endl;

	float f = Serializer::serializeIntToFloat(i0);
	std::bitset<32> bits2(static_cast<unsigned long>(f));
	std::cout << "Float as bits: " << bits2 << std::endl;

	int i1 = Serializer::deserializeFloatToInt(f);
	std::bitset<32> bits3(static_cast<unsigned long>(i1));
	std::cout << "Int as bits: " << bits3 << std::endl;

	return 0;
}
