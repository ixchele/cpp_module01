#pragma once
#include <string>

class Zombie {
	private:
		std::string _name;
	public:
		void	annouce(void);

		Zombie(std::string);
		~Zombie();
};
