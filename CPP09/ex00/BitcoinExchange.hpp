#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);

		// Destructor
		~BitcoinExchange();

		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &rhs);

	private:

};

#endif