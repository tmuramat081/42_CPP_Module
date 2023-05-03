#ifndef REPOSITORY_HPP
# define REPOSITORY_HPP

template<typename T>
class Repsoitory
{
public:
	virtual ~Repository(){};

	virtual void add(const T& item) = 0;
	virtual T get(int id) = 0;
	virtual T[] getAll() const = 0;
};

#endif