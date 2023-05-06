#ifndef PHONEBOOK_CONSTANT_HPP
#define PHONEBOOK_CONSTANT_HPP

#include <iostream>

/** 電話帳定数クラス */
class PhoneBookConstant
{
public:
	/** 受付コマンド */
	class Command
	{
	public:
		static const std::string SEARCH;
		static const std::string ADD;
		static const std::string EXIT;
	};

	/** 保持できるレコードの最大数 */
	static const int RECORD_MAX = 8;
};


#endif
