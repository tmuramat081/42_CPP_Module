#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <time.h>

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

static bool isPrime(int num, const std::vector<int> &primes)
{
	for (std::vector<int>::const_iterator p = primes.begin(); p != primes.cend(); ++p)
	{
		if (*p * *p > num)
			break;
		if (num % *p == 0)
			return false;
	}
	return true;
}

static void getPrimes(std::vector<int> &primes, const size_t n)
{
	primes.push_back(2);
	for (int num = 3; primes.size() < n; num += 2)
	{
		if (isPrime(num, primes))
		{
			primes.push_back(num);
		}
	}
}

static void successful_test1()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << BLUE << "Shortest: " << sp.shortestSpan() << std::endl << DEFAULT;
	std::cout << BLUE << "Longest: " << sp.longestSpan() << std::endl << DEFAULT;
}

static void successful_test2()
{
	Span sp = Span(10000);

	// 10000個の素数を取得
	std::vector<int> p;
	getPrimes(p, 10000);

	// 素数をシャッフル
    std::srand(std::time(0));
	std::random_shuffle(p.begin(), p.end());

	for (std::vector<int>::const_iterator itr = p.begin(); itr != p.cend(); ++itr)
	{
		std::cout << *itr;
		if (itr != p.cend()) std::cout  << ", ";
		sp.addNumber(*itr);
	}
	std::cout << std::endl;

	std::cout << BLUE << "Shortest: " << sp.shortestSpan() << std::endl << DEFAULT;
	std::cout << BLUE << "Longest: " << sp.longestSpan() << std::endl << DEFAULT;
}

static void failure_test()
{
	Span sp = Span(1);

	sp.addNumber(6);

	try
	{
		sp.addNumber(3);
	}
	catch (std::length_error &e)
	{
		std::cerr << RED << e.what() << std::endl << DEFAULT;
	}

	try
	{
		sp.shortestSpan();
	}
	catch (std::range_error &e)
	{
		std::cerr << RED << e.what() << std::endl << DEFAULT;
	}

	try
	{
		sp.longestSpan();
	}
	catch (std::range_error &e)
	{
		std::cerr << RED << e.what() << std::endl << DEFAULT;
	}
}

int main()
{
	successful_test1();
	successful_test2();
	failure_test();

	return 0;
}
