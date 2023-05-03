#ifndef CONTACT_REPOSITORY_HPP
# define CONTACT_REPOSITORY_HPP

#include "Repository.hpp"

template <typename T>
class ContactRepository : public Repository<T>
{
public:
	virtual void add(const T& contact)
	{
		_contact_store[_index % 8] = contact;
	}

	virtual T[] getAll() const
	{
		return _contact_store;
	}

private:
	T[8] _contact_store;
	int _index;
};

#endif