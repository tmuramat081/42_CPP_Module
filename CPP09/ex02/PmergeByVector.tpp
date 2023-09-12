template<class RandomIt>
void SortByVector::sort(RandomIt first, RandomIt last)
{
	mergeInsertionSort(first, last);
}

template<class RandomIt>
void SortByVector::mergeInsertionSort(RandomIt first, RandomIt last)
{
	typedef typename std::iterator_traits<RandomIt>::value_type ValueType;
	std::ptrdiff_t n = std::distance(first, last);

	if (n <= 1) return ;

	std::vector<ValueType> mainChain;
	std::vector<std::pair<ValueType, ValueType>> pairs;

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

	mergeInsertionSort(mainChain.begin(), mainChain.end());

	for (const auto &p: pairs)
	{
		auto upperBoundIt = std::upper_bound(mainChain.begin(), mainChain.end(), p.second);
		auto insert_pos = std::lower_bound(mainChain.begin(), upperBoundIt, p.first);
		mainChain.insert(insert_pos, p.first);
	}

	std::copy(mainChain.begin(), mainChain.end(), first);
}
