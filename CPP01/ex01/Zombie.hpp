#include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	Zombie();
	~Zombie();
	void announce(void);
	void setName(std::string& name);

private:
	std::string _name;
};
