#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void Harl::complain(std::string level);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	typedef void (* t_error_log)(void);
	t_error_log _logs[4];
};
