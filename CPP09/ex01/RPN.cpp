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

	for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
	{
		char token = *it;

		if (std::isspace(token)) continue;

		if (std::string("+-*/").find(token) != std::string::npos)
		{
			if (_s.size() < 2)
			{
				throw std::invalid_argument("Invalid expression");
			}
			int a = _s.top(); _s.pop();
			int b = _s.top(); _s.pop();

			if (token == '+') _s.push(b + a);
			else if (token == '-') _s.push(b - a);
			else if (token == '*') _s.push(b * a);
			else if (token == '/') {
				if (a == 0)
					throw std::invalid_argument("Invalid expression");
				else
					_s.push(b / a);
			}
		}
		else if (std::isdigit(token))
		{
			int n = token - '0';
			_s.push(n);
		}
		else
		{
			throw std::invalid_argument("Invalid expression");
		}
	}
	return _s.top();
}
