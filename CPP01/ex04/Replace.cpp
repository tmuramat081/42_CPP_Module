#include "Replace.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Replace::Replace() {}

Replace::Replace(
	const std::string &filename,
	const std::string &s1,
	const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

Replace::~Replace() {}

/** キーワードを一括置換する */
void Replace::replaceAll()
{
	/** 読む込むファイルを開く */
	std::ifstream src_file(this->_filename);
	if (!src_file)
	{
		std::cerr << "Error: can't open file:" << this->_filename << std::endl;
		return;
	}

	/** ファイルの内容を文字列ストリームに挿入 */
	std::ostringstream buffer;
	buffer << src_file.rdbuf();
	src_file.close();
	std::string content = buffer.str();

	/** 置換処理 */
	size_t pos = 0;
	while ((pos = content.find(_s1, pos)) != std::string::npos)
	{
		content.erase(pos, _s1.length());
		content.insert(pos, _s2);
		pos += _s2.length();
	}

	/** 書き込むファイルを開く */
	std::ofstream dst_file(_filename + ".replace");
	if (!dst_file)
	{
		std::cerr << "Error: can't open file." << std::endl;
		dst_file.close();
		return;
	}

	/** 置換した文字列を書き込む */
	dst_file << content;
	dst_file.close();
}
