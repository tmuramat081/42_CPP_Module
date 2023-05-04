#ifndef REPOSITORY_HPP
# define REPOSITORY_HPP

template<typename T>
class Repository
{
public:
	virtual ~Repository(){};

	virtual void add(const T& item) = 0;
	virtual T find(int id) const = 0;
};

#endif