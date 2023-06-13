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

	// Member functions
	static inline void trimSpace(std::string &s);
	void calculateValues(const std::string &filename);

private:
	BitcoinExchange();
	std::map<std::string, double> _rates;
	void loadRatesMaster(const std::string &filename);
	void calculateValue(const std::string &date, const double value);

};

#endif
