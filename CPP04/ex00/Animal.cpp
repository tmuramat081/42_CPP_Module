#include "Animal.hpp"

Animal::Animal(){}

Animal::Animal(std::string &type)
{
	this->_type = type;
}

Animal(Animal &other);

Animal::~Animal(){}

