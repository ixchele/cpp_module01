#include <HumanB.hpp>
#include <iostream>

HumanB::HumanB(std::string name) {
	setName(name);
}

void	HumanB::setWeapon(Weapon &weapon) {
	*_weapon = weapon;
}

Weapon	HumanB::getWeapon(void) const {
	return *_weapon;
}

void	HumanB::setName(std::string name) {
	_name = name;
}

std::string	HumanB::getName(void) const {
	return _name;
}

void	HumanB::attack(void) {
	std::cout << getName();
	std::cout << " attacks with their " << getWeapon().getType() << "\n";
}
