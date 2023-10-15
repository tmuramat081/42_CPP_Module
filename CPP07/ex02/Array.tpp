template <typename T>
Array<T>::Array()
{
	this->_array = NULL;
	this->_n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	this->_n = n;
}

template <typename T>
Array<T>::Array(const Array &other)
{
	this->_n = other._n;
	this->_array = new T[_n];
	for (size_t i = 0; i < _n; ++i)
	{
		this->_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
	this->_array = NULL;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		T* new_array = new T[_n];
		for (size_t i = 0; i < _n; ++i)
		{
			new_array[i] = rhs._array[i];
		}
		delete[] this->_array;
		this->_n = rhs._n;
		this->array = new_array;
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](size_t index)
{
	if (index < 0 || this->_n <= index)
	{
		throw std::out_of_range("Error: out of range");
	}
	return _array[index];
}

template<typename T>
size_t Array<T>::size() const
{
	return this->_n;
}
