template<class RandomIt>
void SortByVector::sort(RandomIt first, RandomIt last)
{
	mergeInsertSort(first, last);
}

template<class RandomIt>
void SortByVector::mergeInsertSort(RandomIt first, RandomIt last)
{
	typedef typename std::iterator_traits<RandomIt>::value_type ValueType;
	std::ptrdiff_t n = std::distance(first, last);

	if (n < 2) return ;

	std::vector<ValueType> mainChain;
	std::vector<std::pair<ValueType, ValueType> > pairs;

	RandomIt it = first;
	while (std::distance(it, last) > 1)
	{
		RandomIt next = std::next(it);
		ValueType minVal = std::min(*it, *next);
		ValueType maxVal = std::max(*it, *next);

		pairs.push_back(std::make_pair(minVal, maxVal));
		mainChain.push_back(maxVal);

		std::advance(it, 2);
	}
	if (it != last)
	{
		mainChain.push_back(*it);
	}

	mergeInsertSort(mainChain.begin(), mainChain.end());

	for (typename std::vector<std::pair<ValueType, ValueType> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		const std::pair<ValueType, ValueType>& p = *it;
		typename std::vector<ValueType>::iterator upperBoundIt = std::upper_bound(mainChain.begin(), mainChain.end(), p.second);
		typename std::vector<ValueType>::iterator insert_pos = std::lower_bound(mainChain.begin(), upperBoundIt, p.first);

		mainChain.insert(insert_pos, p.first);
	}

	std::copy(mainChain.begin(), mainChain.end(), first);
}
