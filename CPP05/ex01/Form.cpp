#include "Form.hpp"

// Constructors
Form::Form(): _name("default"), _is_signed(false), _required_grade(100){}

Form::Form(const Form &other)
{
	this->_is_signed = other._is_signed;
	this->_required_grade = other._required_grade;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	(void) assign;
	return *this;
}

