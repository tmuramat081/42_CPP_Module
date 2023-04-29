#include "Wepon.hpp"

class HumanB {
	public:
		HumanB();
		~HumanB();

		void attack();

	private:
		Wepon wepon;
		std::string name;
};

