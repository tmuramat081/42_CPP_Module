#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
public:
	// Constructors
	BitcoinExchange(const std::string &filename, bool visualMode = false);
	BitcoinExchange(const BitcoinExchange &other);

	// Destructor
	~BitcoinExchange();

	// Operators
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	// Member functions
	static inline void trimSpace(std::string &s);
	void calculateAllValues(const std::string &filename);
	void setVisualMode(bool visualMode);

private:
	bool _visualMode;
	BitcoinExchange();
	std::map<std::string, float> _rates;
	void loadRatesMaster(const std::string &filename);
	void calculateValue(const std::string &date, const float value);
	bool validateDateFormat(const std::string &date);
};

#endif
