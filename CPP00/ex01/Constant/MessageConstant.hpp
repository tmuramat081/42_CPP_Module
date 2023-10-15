#ifndef MESSAGE_CONSTANT_HPP
#define MESSAGE_CONSTANT_HPP

#include <iostream>

/** 電話帳メッセージ定数クラス */
class MessageConstant
{
public:
	/** 名 */
	static const std::string FIRST_NAME;
	/** 姓 */
	static const std::string LAST_NAME;
	/** 通称 */
	static const std::string NICKNAME;
	/** 電話番号 */
	static const std::string PHONE_NUMBER;
	/** ☆秘密☆ */
	static const std::string SECRET;

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

	/** 入力メッセージを動的に作成 */
	static std::string inputItemMessage(const std::string &item);

	/** 異常系 */
	class Error
	{
	public:
		/**　"不正なコマンドです" */
		static const std::string INVALID_COMMAND;
		/**　"不正な入力値です" */
		static const std::string INVALID_INPUT;
		/**　"不正な名前です" */
		static const std::string INVALID_NAME;
		/**　"不正な名前です" */
		static const std::string INVALID_PHONE_NUMBER;
		/** "入力が空です" */
		static const std::string EMPTY_LINE;
		/**　"有効な文字数内で入力してください" */
		static const std::string INVALID_LENGTH;
		/**　"有効範囲内の数値を入力してください" */
		static const std::string OUT_OF_RANGE;
		/**　"連絡先のレコードが存在しません" */
		static const std::string NOT_EXIST_CONTACT;
	};
};

#endif
