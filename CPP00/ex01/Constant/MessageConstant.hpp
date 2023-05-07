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
	/** "連絡先を登録しますか？" */
	static const std::string CREATE_CHECK;
	/** "連絡先を登録しました" */
	static const std::string CREATE_SUCCESS;
	/** "アプリケーションを終了しますが、よろしいですか？" */
	static const std::string EXIT_CHECK;
	/** "アプリケーションを終了します" */
	static const std::string EXIT_APP;

	/** 異常系 */
	class Error
	{
	public:
		/**　"不正なコマンドです" */
		static const std::string INVALID_COMMAND;
		/**　"不正な入力値です" */
		static const std::string INVALID_INPUT;
		/**　"有効な文字数で入力してください" */
		static const std::string INVALID_LENGTH;
		/**　"有効範囲内の数値を入力してください" */
		static const std::string OUT_OF_RANGE;
		/**　"連絡先のレコードが存在しない" */
		static const std::string NOT_EXIST_CONTACT;
	};
};

#endif
