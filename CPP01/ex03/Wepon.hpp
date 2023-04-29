#include <iostream>

class Wepon
{
public:
	Wepon(){};
	~Wepon(){};

	std::string &getType() const;
	void setType(std::string type);

private:
	std::string type;
};
