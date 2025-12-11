#pragma once
#include <string>

class Zombie {
	private:
		std::string _name;
	public:
		void	setName(std::string);
		void	announce(void);

		Zombie(void);
		~Zombie(void);
};
