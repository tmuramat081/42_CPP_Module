#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
public:
	// Constructors
	Brain();
	Brain(const Brain &other);

	// Destructor
	~Brain();

	// Operators
	Brain &operator=(const Brain &rhs);

	// Getters / Setters
	std::string getIdea(const int index) const;
	void setIdea(const int index, const std::string &idea);

private:
	static const int IDEA_MAX = 100;
	std::string _ideas[IDEA_MAX];
};

#endif
