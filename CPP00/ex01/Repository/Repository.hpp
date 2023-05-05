#ifndef REPOSITORY_HPP
# define REPOSITORY_HPP

template<typename T>
class Repository
{
public:
	virtual ~Repository(){};

	virtual void insert(const T& item) = 0;
	virtual T select(int id) const = 0;
};

#endif