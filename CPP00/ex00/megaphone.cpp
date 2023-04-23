#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	std::string str = argv[1];
	for (int i = 2; i < argc; ++i) {
		str.append(" ");
		str.append(argv[i]);
	}
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << str << std::endl;
	return (0);
}
