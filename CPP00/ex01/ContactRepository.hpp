#ifndef CONTACT_REPOSITORY_HPP
#define CONTACT_REPOSITORY_HPP

#include "Repository.hpp"

template <typename T>
class ContactRepository : public Repository<T>
{
public:
	virtual void add(const T &contact)
	{
		_contact_store[_index % 8] = contact;
	}

	virtual T find(int id) const
	{
		for (int i = 0; i < 8; i++)
		{
			if (i == _contact_store[i].index)
				return _contact_store[i];
		}
		return Contact() ;
	}

private:
	T _contact_store[8];
	int _index;
};

#endif