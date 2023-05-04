#ifndef CONTACT_REPOSITORY_HPP
# define CONTACT_REPOSITORY_HPP

#include "Repository.hpp"

template <typename T>
class ContactRepository : public Repository<T>
{
public:
	virtual void add(const T &contact)
	{
		contactStore[_index % 8] = contact;
	}

	virtual T find(int id) const
	{
		return contactStore[id];
	}

	T *findAll(void) const
	{
		return contactStore;
	}

private:
	T contactStore[8];
	int _index;
};

#endif