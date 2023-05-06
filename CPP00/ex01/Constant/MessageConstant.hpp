#ifndef MESSAGE_CONSTANT_HPP
#define MESSAGE_CONSTANT_HPP

#include <iostream>

/** 電話帳メッセージ定数クラス */
class MessageConstant
{
public:
	/** "コマンドを入力してください" */
	static const std::string ENTER_COMMAND;
	/** "任意のインデックスを指定してください"*/
	static const std::string ENTER_INDEX;
	/** "アプリケーションを終了しますが、よろしいですか？" */
	static const std::string EXIT_CHECK;
	/** "アプリケーションを終了します" */
	static const std::string EXIT_APP;

	class Error
	{
	public:
		static const std::string INVALID_COMMAND;
		static const std::string NOT_EXIST_CONTACT;
	};
};

#endif
