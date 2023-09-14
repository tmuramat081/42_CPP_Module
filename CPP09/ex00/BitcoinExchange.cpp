#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <limits>
#include <functional>
#include <algorithm>

// Constructors
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename, bool visualMode)
{
	this->loadRatesMaster(filename);
	_visualMode = visualMode;
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
void BitcoinExchange::calculateValue(const std::string &date, const float value)
{
	static float old_value;

	if (!validateDateFormat(date))
	{
		throw std::runtime_error("bad input => " + date);
	}
	if (value < 0)
	{
		throw std::range_error("not a positive number.");
	}
	else if (value > 1000)
	{
		throw std::range_error("too large a number.");
	}
	// 入力された日付より大きい最初の値を取得
	std::map<std::string, float>::iterator iter = _rates.upper_bound(date);

	// データがないか、全てが指定した日付より新しい場合はエラー
	if (iter == _rates.begin())
	{
		throw std::runtime_error("bad input");
	}
	float new_value = (--iter)->second * value;
	if (_visualMode == true)
	{
		const std::string color = old_value < new_value ? "\033[32m" : "\033[31m";
		std::cout << color << date << " => " << value << " = " << new_value << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << date << " => " << value << " = " << new_value << std::endl;
	}
	old_value = new_value;
}

void BitcoinExchange::calculateAllValues(const std::string &filename)
{
	// 入力ファイルを開く
	std::fstream file(filename);
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open file:" + filename);
	}

	// 先頭行を解析する
	std::string line, date, value;
	if (std::getline(file, date, '|') && std::getline(file, value))
	{
		// 前後の空白をトリム
		trimSpace(date);
		trimSpace(value);
		if (date != "date" || value != "value")
		{
			throw std::runtime_error("Invalid header.");
		}
	}

	while (std::getline(file, line))
	{
		// 文字列を分割
		std::stringstream ss(line);
		float fvalue = 0;
		if (std::getline(ss, date, '|') && std::getline(ss, value))
		{

			// 前後の空白をトリム
			trimSpace(date);
			trimSpace(value);
			try
			{
				fvalue = std::stod(value);
				this->calculateValue(date, fvalue);
			}
			catch (std::exception &e)
			{
				std::cerr << "\033[31mError: " << e.what() << "\033[0m" << std::endl;
			}
		}
		else
		{
			std::cerr << "\033[31m" << "bad input => " << line << "\033[0m" << std::endl;
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

	std::string line, date, rateStr;
	// 先頭行のヘッダーを検証
	if (std::getline(file, date, ',') && std::getline(file, rateStr))
	{
		// 前後の空白をトリム
		trimSpace(date);
		trimSpace(rateStr);
		if (date != "date" || rateStr != "exchange_rate")
		{
			throw std::runtime_error("Invalid header.");
		}
	}
	while (std::getline(file, line))
	{
		// カンマで分割
		std::stringstream ss(line);
		if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
		{
			float rate = std::stod(rateStr);
			_rates[date] = rate;
		}
		else
		{
			throw std::runtime_error("bad input => " + line);
		}
	}
}

/**
 * @brief 前後の空白をトリムする
 *
 * @param s
 */
void BitcoinExchange::trimSpace(std::string &s)
{
	// left trim
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));

	// right trim
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

/**
 * @brief 日付(YYYY/MM/DD)を検証する
 *
 * @param date
 * @return true
 * @return false
 */
bool BitcoinExchange::validateDateFormat(const std::string &date)
{
	if (date.length() != 10)
	{
		return false;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		return false;
	}

	std::istringstream ss(date);
	int year, month, day;
	char dash1, dash2;

	ss >> year >> dash1 >> month >> dash2 >> day;

	if (!ss || ss.peek() != EOF)
	{
		return false;
	}
	if (month < 1 || month > 12)
	{
		return false;
	}
	if (day < 1 || day > 31)
	{
		return false;
	}
	return true;
}

void BitcoinExchange::setVisualMode(bool visualMode)
{
	_visualMode = visualMode;
}
