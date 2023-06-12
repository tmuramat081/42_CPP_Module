#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <limits>

// Constructors
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	this->loadRates(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_rates = other._rates;
}

// Destructor
BitcoinExchange::~BitcoinExchange(){}

// Operators
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_rates = rhs._rates;
	}
	return *this;
}

void BitcoinExchange::calculateValue(const std::string &date, const double value)
{
	if (date.empty())
	{
		throw std::invalid_argument("bad input => " + date);
	}
	if (value <= 0)
	{
		throw std::range_error("not a positive number");
	}
	else if (value > std::numeric_limits<int>::max())
	{
		throw std::range_error("too large a number");
	}
	std::cout << date << " => " << value << " = " << _rates[date] * value << std::endl;
}

void BitcoinExchange::loadRates(const std::string &filename)
{
	std::fstream file(filename);
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open file:" + filename);
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, rateStr;
		if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
		{
			double rate = std::stod(rateStr);
			_rates[date] = rate;
		}
		else
		{
			throw std::runtime_error("bad input => " + line);
		}
	}
}
