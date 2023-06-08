template <typename T>
int easyfind(const T &c, const int index)
{
	int pos = 0;
	for (typename T::const_iterator itr = c.begin(); itr != c.end(); ++itr, ++pos)
	{
		if (*itr == index)
		{
			return pos;
		}
	}
	return -1;
}
