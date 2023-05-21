#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>

class Ice
{
	public:
		// Constructors
		Ice();
		Ice(const Ice &copy);
		Ice(void clone());

		// Destructor
		~Ice();

		// Operators
		Ice & operator=(const Ice &assign);

		// Getters / Setters
		void getClone()() const;

	private:
		void _clone();

};

#endif