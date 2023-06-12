#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
public:
	// Constructors
	BitcoinExchange(const std::string &filename);
	BitcoinExchange(const BitcoinExchange &other);

	// Destructor
	~BitcoinExchange();

	// Operators
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void calculateValue(const std::string &date, const double value);

private:
	BitcoinExchange();
	std::map<std::string, double> _rates;
	void loadRates(const std::string &filename);
};

#endif
