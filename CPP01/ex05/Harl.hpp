#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void complain(std::string level);
	void complainFilter(std::string level);

private:
	int	_hash(std::string str);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void (Harl::* _logs[4])(void);
	std::string _levels[4];
};
