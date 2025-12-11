#pragma once
#include <string>

class Weapon {
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		std::string	getType(void) const;
		void		setType(std::string type);
};
