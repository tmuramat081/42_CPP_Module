#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

std::ostream &operator<<(std::ostream &os, const Data &data)
{
	os << "s1: " << data.s1 << std::endl;
	os << "s2: " << data.s2 << std::endl;
	os << "n: " << data.n;
	return os;
}
