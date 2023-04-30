#include "Harl.hpp"

Harl::Harl(){
	this->_logs[0] = &Harl::debug;
	this->_logs[1] = &Harl::info;
	this->_logs[2] = &Harl::warning;
	this->_logs[3] = &Harl::error;
};

Harl::~Harl(){};

void Harl::complain(std::string level)
{
}

void debug()
{
	std::cerr << "Preparing to connect to the database, ready, set, go!" << std::endl;
}

void info()
{
	std::cerr << "Woohoo! Successfully connected to the database!" << std::endl;
}

void warning()
{
	std::cerr << "Hold on a sec! You're using a deprecated API. Maybe give the new one a try?" << std::endl;
}

void error()
{
	std::cerr << "Oops! Can't find the file anywhere... Make sure to double-check the path!" << std::endl;
}
