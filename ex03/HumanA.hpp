#pragma once
#include <string>
#include <Weapon.hpp>

class HumanA {
	private:
		std::string	_name;
		Weapon		&_weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		void		setWeapon(Weapon &weapon);
		Weapon		getWeapon(void) const;
		std::string	getName(void) const;
		void		setName(std::string name);
		void		attack(void);
};
