#include "Wepon.hpp"

class HumanA {
	public:
		HumanA();
		~HumanA();

		void attack();

	private:
		Wepon wepon;
		std::string name;
};

