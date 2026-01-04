#include "Weapon.hpp"
#include <HumanB.hpp>
#include <iostream>

HumanB::HumanB(std::string name) {
	setName(name);
	_weapon = new Weapon("hand");
}

HumanB::~HumanB(void) {
	delete _weapon;
}

void	HumanB::setWeapon(Weapon *weapon) {
	if (!weapon)
		return;
	_weapon = weapon;
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
