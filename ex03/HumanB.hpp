#pragma once
#include <string>
#include <Weapon.hpp>

class HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB(std::string name);
		void		setWeapon(Weapon &weapon);
		Weapon		getWeapon(void) const;
		void		setName(std::string name);
		std::string	getName(void) const;
		void		attack(void);
};

