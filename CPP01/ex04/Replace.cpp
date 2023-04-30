#include "Replace.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Replace::Replace(){}

Replace::Replace(const std::string &filename, const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

Replace::~Replace() {}

/** replace all keywords */
void Replace::replaceAll()
{
	std::ifstream ifs(this->_filename);
	if (!ifs)
	{
		std::cerr << "Error: can't open file." << std::endl;
		return ;
	}
	std::ostringstream buffer;
	buffer << ifs.rdbuf();
	std::string content = buffer.str();
	size_t pos = 0;
	while((pos = content.find(_s1, pos)) != std::string::npos)
	{
		content.erase(pos, _s1.length());
		content.insert(pos, _s2);
		content.replace(pos, _s1.length(), _s2);
		pos += _s2.length();
	}

	std::ofstream ofs(_filename + ".replace");
	if (!ofs)
	{
		std::cerr << "Error: can't open file." << std::endl;
		return ;
	}
	ofs << content;
	ifs.close();
	ofs.close();
}
