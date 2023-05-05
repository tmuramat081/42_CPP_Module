#ifndef CONTACT_REPOSITORY_HPP
# define CONTACT_REPOSITORY_HPP

#include "Repository.hpp"

template <typename T>
class ContactRepository : public Repository<T>
{
public:
	static const int MAX_RECORD = 8;
	virtual void insert(const T &contact)
	{
		contactStore[_index % MAX_RECORD] = contact;
	}

	virtual T select(int id) const
	{
		return contactStore[id];
	}

private:
	T contactStore[MAX_RECORD];
	int _index;
};

#endif