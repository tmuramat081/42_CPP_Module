#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	for (int i = 0; i < IDEA_MAX; ++i)
	{
		this->_ideas[i] = "None";
	}
	std::cout << "\033[0;33mDefault Constructor called of Brain\033[0m" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < IDEA_MAX; ++i)
	{
		this->_ideas[i] = other._ideas[i];
	}
	std::cout << "\033[0;33mCopy Constructor called of Brain\033[0m" << std::endl;
}

// Destructor
Brain::~Brain()
{
	std::cout << "\033[0;31mDestructor called of Brain\033[0m" << std::endl;
}

// Operators
Brain &Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < IDEA_MAX; ++i)
		{
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdea(const int index) const
{
	return this->_ideas[index];
}

void Brain::setIdea(const int index, std::string &idea)
{
	this->_ideas[index] = idea;
}
