#include <Harl.hpp>
#include <iostream>
#include <string>

int main (int ac, char **av) {
	if (ac != 2)
		return std::cerr << "Usage : <complaining_level> (DEBUG, INFO, WARNING, ERROR)", -1;

	std::string	level = av[1];
	Harl		complainter;
	complainter.complain(level);

	return 0;
}
