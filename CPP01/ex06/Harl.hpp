#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	int getErrorLevelKey(std::string level);
	void complainFilter(std::string level);

private:
	static const int N_LOG_LEVELS = 4;
	static const int DEBUG = 0;
	static const int INFO = 1;
	static const int WARNING = 2;
	static const int ERROR = 3;
	static const int NONE = 4;

	std::string _levels[N_LOG_LEVELS];
	typedef void (Harl::*t_log_funcs[N_LOG_LEVELS])(void);
	t_log_funcs _logs;
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
};

#endif