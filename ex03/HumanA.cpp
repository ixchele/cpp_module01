#include <HumanA.hpp>
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) {
	setName(name);
}

void	HumanA::setWeapon(Weapon &weapon) {
	_weapon = weapon;
}

Weapon	HumanA::getWeapon(void) const {
	return _weapon;
}

void	HumanA::setName(std::string name) {
	_name = name;
}

std::string	HumanA::getName(void) const {
	return _name;
}

void	HumanA::attack(void) {
	std::cout << getName();
	std::cout << " attacks with their " << getWeapon().getType() << "\n";
}
