#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <string>

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
	static float serializeIntToFloat(int i);
	static int deserializeFloatToInt(float f);

private:
	Serializer();
};

std::ostream &operator<<(std::ostream &os, const Data &data);

#endif
