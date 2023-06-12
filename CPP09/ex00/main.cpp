#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <functional>
#include <algorithm>

static inline void trimSpace(std::string &s)
{
	// left trim
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));

	// right trim
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

void calculateValue(std::string filename)
{
	// DBのマスタを読み込む
	BitcoinExchange be("./data.csv");

	// 入力ファイルを開く
	std::fstream file(filename);

	// 先頭の一行をスキップする
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		// 文字列を分割
		std::stringstream ss(line);
		std::string date, value;
		std::getline(ss, date, '|');
		std::getline(ss, value);

		// 前後の空白をトリム
		trimSpace(date);
		trimSpace(value);
		try
		{
			be.calculateValue(date, std::stod(value));
		}
		catch(std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 0;
	}
	try
	{
		calculateValue(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error:" << e.what() << std::endl;
	}
	return 0;
}
