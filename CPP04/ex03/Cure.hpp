#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>

class Cure
{
	public:
		// Constructors
		Cure();
		Cure(const Cure &copy);
		Cure(void clone());

		// Destructor
		~Cure();

		// Operators
		Cure & operator=(const Cure &assign);

		// Getters / Setters
		void getClone()() const;

	private:
		void _clone();

};

#endif