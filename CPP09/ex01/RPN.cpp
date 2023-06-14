#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdio.h>

// Constructors
RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	this->_s = other._s;
}

// Destructor
RPN::~RPN() {}

// Operators
RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->_s = rhs._s;
	}
	return *this;
}

int RPN::calculate(const std::string &s)
{
	if (s.empty())
	{
		throw std::invalid_argument("Invalid expression");
	}
	std::istringstream iss(s);
	std::string token;

	while (iss >> token)
	{
		if (std::string("+-*/").find(token) != std::string::npos)
		{
			if (_s.size() < 2)
			{
				throw std::invalid_argument("Invalid expression");
			}
			int a = _s.top(); _s.pop();
			int b = _s.top(); _s.pop();

			if (token == "+") _s.push(b + a);
			else if (token == "-") _s.push(b - a);
			else if (token == "*") _s.push(b * a);
			else if (token == "/") _s.push(b / a);
		}
		else
		{
			int n = std::stoi(token);
			_s.push(n);
		}
	}
	return _s.top();
}
