#ifndef CONTACT_REPOSITORY_HPP
#define CONTACT_REPOSITORY_HPP

#include "Repository.hpp"
#include "PhoneBookConstant.hpp"

/** 連絡先リポジトリ */
template <typename T>
class ContactRepository : public Repository<T>
{
public:
	static const int RECORD_MAX = PhoneBookConstant::RECORD_MAX;

	ContactRepository() : _index(0)
	{
		for (int i = 0; i < RECORD_MAX; ++i)
		{
			_contactStore[i].isDeleted = true;
		}
	}

	virtual int insert(const T &contact)
	{
		int insert_index;

		insert_index = this->_index % RECORD_MAX;
		this->_contactStore[insert_index] = contact;
		this->_index += 1;
		return insert_index;
	}

	virtual T select(int id) const
	{
		if (id < 0 || RECORD_MAX <= id)
		{
			throw std::out_of_range("Index out of range");
		}
		return this->_contactStore[id];
	}

private:
	T _contactStore[RECORD_MAX];
	int _index;
};

#endif
