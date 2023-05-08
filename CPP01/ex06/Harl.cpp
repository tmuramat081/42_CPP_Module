#include "Harl.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

Harl::Harl()
{
	this->_logs[0] = &Harl::_debug;
	this->_logs[1] = &Harl::_info;
	this->_logs[2] = &Harl::_warning;
	this->_logs[3] = &Harl::_error;

	this->_levels[0] = "DEBUG";
	this->_levels[1] = "INFO";
	this->_levels[2] = "WARNING";
	this->_levels[3] = "ERROR";
}

Harl::~Harl(){}

void Harl::complain(std::string level)
{
	for (int i = 0; i < N_LOG_LEVELS; i++)
	{
		if (this->_levels[i] == level)
		{
			(this->*(_logs[i]))();
			return;
		}
	}
}

void Harl::complainFilter(std::string level)
{
	bool expected = false;
	std::cout << "[ " << level << " ]" << std::endl;

	for (int i = 0; i < N_LOG_LEVELS; i++)
	{
		if (level == this->_levels[i] || expected == true)
		{
			(this->*(_logs[i]))();
			expected = true;
		}
	}
}

void Harl::_debug()
{
	std::cerr << BLUE;
	std::cerr << "Preparing to connect to the database, ready, set, go!";
	std::cerr << DEFAULT;
	std::cerr << std::endl;
}

void Harl::_info()
{
	std::cerr << GREEN;
	std::cerr << "Woohoo! Successfully connected to the database!";
	std::cerr << DEFAULT;
	std::cerr << std::endl;
}

void Harl::_warning()
{
	std::cerr << YELLOW;
	std::cerr << "Hold on a sec! You're using a deprecated API. Maybe give the new one a try?";
	std::cerr << DEFAULT;
	std::cerr << std::endl;
}

void Harl::_error()
{
	std::cerr << RED;
	std::cerr << "Oops! Can't find the file anywhere... Make sure to double-check the path!";
	std::cerr << DEFAULT;
	std::cerr << std::endl;
}
