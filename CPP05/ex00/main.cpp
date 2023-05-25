#include "Bureaucrat.hpp"

int main ()
{

	try
	{
		Bureaucrat b;
	}
	catch(...)
	{
		std::cerr << "Exception" << std::endl;
	}
	return 0;
}
