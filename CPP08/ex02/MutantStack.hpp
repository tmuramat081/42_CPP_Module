#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>

template <typename T>
class MutantStack
{
public:
	// Constructors
	MutantStack();
	MutantStack(const MutantStack &copy);

	// Destructor
	~MutantStack();

	// Operators
	MutantStack &operator=(const MutantStack &assign);

	// Member functions
	void push(const T &value);
	void pop();
	T top();
	bool empty();
	size_t size();

	// Iterator
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::iterator iterator;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

private:
	std:: deque<T> _stack;
};

#include "MutantStack.tpp"

#endif
