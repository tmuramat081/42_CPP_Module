#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	static const int N_LOG_LEVELS = 4;
	typedef void (Harl::*t_log_funcs[N_LOG_LEVELS])(void);
	t_log_funcs _logs;
	std::string _levels[N_LOG_LEVELS];
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
};

#endif