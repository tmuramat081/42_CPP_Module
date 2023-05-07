#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

/** リポジトリ抽象クラス */
template <typename T>
class Repository
{
public:
	virtual ~Repository(){};

	virtual int insert(const T &item) = 0;
	virtual T select(int id) const = 0;

};

#endif
