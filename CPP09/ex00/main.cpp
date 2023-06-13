#include "BitcoinExchange.hpp"

void calculateValues(const std::string &filename)
{
	// DBのマスタを読み込む
	BitcoinExchange be("./data.csv");
	// 入力した値を元に価格を算出
	be.calculateValues(filename);
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
		calculateValues(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
