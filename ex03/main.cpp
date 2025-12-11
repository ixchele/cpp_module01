#include <HumanB.hpp>
#include <HumanA.hpp>
#include <iostream>

int main()
{
	{
		Weapon club("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();

		std::cout << "In this case, we use a reference because HumanA must\n";
		std::cout << "have a weapon at construction time. A reference cannot be\n";
		std::cout << "empty, so this guarantees that Bob always has a weapon.\n";
	}

	{
		Weapon club("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();

		std::cout << "In this case, we use a pointer because HumanB may or may not\n";
		std::cout << "have a weapon. A reference must be initialized in the constructor,\n";
		std::cout << "so it cannot represent the possibility of \"no weapon\".\n";
	}

	return 0;
}
