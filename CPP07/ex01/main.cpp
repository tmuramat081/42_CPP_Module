#include "iter.hpp"
#include <string>
#include <iostream>

// void intFunc(const int elem)
// {
// 	std::cout << elem << std::endl;
// }

// void strFunc(const std::string elem)
// {
// 	std::cout << elem << std::endl;
// }

// int main()
// {
// 	int array0[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	std::string array1[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

// 	iter(array0, 10, intFunc);
// 	iter(array1, 10, strFunc);

// 	return (0);
// }

class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
	o << rhs.get();
	return o;
}

template< typename T >
void print( T& x )
{
	std::cout << x << std::endl;
	return;
}

template <typename T>
void print(T param)
{
	std::cout << param << std::endl;
}

int main() {
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print<const int> );
	iter( tab2, 5, print<Awesome> );

	return 0;
}
