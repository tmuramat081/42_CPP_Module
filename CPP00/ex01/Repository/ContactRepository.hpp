#ifndef CONTACT_REPOSITORY_HPP
# define CONTACT_REPOSITORY_HPP

#include "Repository.hpp"
#include "PhoneBookConstant.hpp"

template <typename T>
class ContactRepository : public Repository<T>
{
public:
	static const int MAX_RECORD = 8;
	ContactRepository(): _index(0) {
		for(int i = 0; i < PhoneBookConstant::RECORD_MAX; ++i)
		{
			contactStore[i].isDeleted = true;
		}
	};
	~ContactRepository(){};

	virtual int insert(const T &contact)
	{
		int insert_index;

		insert_index = _index % MAX_RECORD;
		contactStore[insert_index] = contact;
		_index += 1;
		return insert_index;
	}

	virtual T select(int id) const
	{
		if (id < 0 || MAX_RECORD <= id)
		{
			throw std::out_of_range("Index out of range");
		}
		return contactStore[id];
	}

private:
	T contactStore[MAX_RECORD];
	int _index;
};

#endif
