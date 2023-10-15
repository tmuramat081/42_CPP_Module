#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
public:
	// Constructors
	RPN();
	RPN(const RPN &other);

	// Destructor
	~RPN();

	// Operators
	RPN & operator=(const RPN &rhs);

	// Member functions
	int calculate(const std::string &s);

private:
	std::stack<int> _s;
};

#endif
