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

Harl::~Harl() {}

int Harl::getErrorLevelKey(std::string level)
{
	int index;

	for (index = 0; index < N_LOG_LEVELS; ++index)
	{
		if (this->_levels[index] == level)
		{
			return index;
		}
	}
	return index;
}

void Harl::complainFilter(std::string level)
{
	int key = getErrorLevelKey(level);
	if (key == NONE)
	{
		std::cerr << "Error: invalid log level." << std::endl;
		return;
	}
	std::cout << "[ " << level << " ]" << std::endl;

	switch (key)
	{
	case Harl::DEBUG:
		(this->*_logs[DEBUG])();
	case Harl::INFO:
		(this->*_logs[INFO])();
	case Harl::WARNING:
		(this->*_logs[WARNING])();
	case Harl::ERROR:
		(this->*_logs[ERROR])();
	default:
		break;
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
