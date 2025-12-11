#include <Zombie.hpp>
#include <iostream>
#include <string>

# define COLOR_GREEN       "\001\033[0;32m\002"
# define COLOR_RESET       "\001\033[0m\002"
# define COLOR_RED         "\001\033[0;31m\002"

Zombie::Zombie(std::string name) : _name(name) {
	annouce();
}

Zombie::~Zombie(void) {
	std::cout << COLOR_RED;
	std::cout << _name << "'s brain was destroyed";
	std::cout << COLOR_RESET << std::endl;

}

void Zombie::annouce(void) {
	std::cout << COLOR_GREEN;
	std::cout << _name << ": BraiiiiiiinnnzzzZ..";
	std::cout << COLOR_RESET << std::endl;
}
