#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>

class Replace
{
public:
	Replace();
	Replace(const std::string &filename, const std::string &s1, const std::string &s2);
	~Replace();

	void replaceAll();

private:
	std::string _filename;
	std::string _s1;
	std::string _s2;
};

#endif