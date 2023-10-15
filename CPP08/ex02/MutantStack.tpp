template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
	this->_stack = other._stack;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs)
{
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
	}
	return *this;
}

template <typename T>
void MutantStack<T>::push(const T &value)
{
	_stack.push_back(value);
}

template <typename T>
void MutantStack<T>::pop()
{
	_stack.pop_back();
}

template <typename T>
T MutantStack<T>::top()
{
	return _stack.back();
}

template <typename T>
bool MutantStack<T>::empty()
{
	return _stack.empty();
}

template <typename T>
size_t MutantStack<T>::size()
{
	return _stack.size();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return _stack.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return _stack.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return _stack.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return _stack.end();
}
