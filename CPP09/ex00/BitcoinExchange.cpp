#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <limits>
#include <functional>
#include <algorithm>

// Constructors
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	this->loadRatesMaster(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_rates = other._rates;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Operators
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_rates = rhs._rates;
	}
	return *this;
}

/**
 * @brief 入力された日付と値をもとに価格を算出する
 *
 * @param date
 * @param value
 */
void BitcoinExchange::calculateValue(const std::string &date, const double value)
{
	if (value <= 0)
	{
		throw std::range_error("not a positive number");
	}
	else if (value > std::numeric_limits<int>::max())
	{
		throw std::range_error("too large a number");
	}
	// 入力された日付より大きい最初の値を取得
	std::map<std::string, double>::iterator iter = _rates.upper_bound(date);

	// データがないか、全てが指定した日付より新しい場合はエラー
	if (iter == _rates.begin())
	{
		throw std::runtime_error("No exchange rate data for the date or earlier.");
	}
	std::cout << date << " => " << value << " = " << (--iter)->second * value << std::endl;
}

void BitcoinExchange::calculateValues(const std::string &filename)
{
	// 入力ファイルを開く
	std::fstream file(filename);

	// 先頭行をスキップする
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		// 文字列を分割
		std::stringstream ss(line);
		std::string date, value;
		double dvalue = 0;

		if (std::getline(ss, date, '|') && std::getline(ss, value))
		{

			// 前後の空白をトリム
			trimSpace(date);
			trimSpace(value);
			try
			{
				dvalue = std::stod(value);
				this->calculateValue(date, dvalue);
			}
			catch (std::exception &e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
}

/**
 * @brief マスタからレートの値を取得し、連想配列に格納する
 *
 * @param filename マスタの参照先
 */
void BitcoinExchange::loadRatesMaster(const std::string &filename)
{
	// ファイルを開く
	std::fstream file(filename);
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open file:" + filename);
	}

	// 先頭行をスキップ
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		// カンマで分割
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

void BitcoinExchange::trimSpace(std::string &s)
{
	// left trim
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));

	// right trim
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}
