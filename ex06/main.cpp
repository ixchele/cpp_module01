#include <Harl.hpp>
#include <iostream>
#include <string>

struct LevelMap {
	std::string	name;
	int			level;
};

LevelMap	levels[] = {
	{"DEBUG", 0},
	{"INFO", 1},
	{"WARNING", 2},
	{"ERROR", 3},
	{std::string(), -1}
};

int	getLevel(const std::string &input)
{
	for (int i = 0; !levels[i].name.empty(); ++i)
	{
		if (input == levels[i].name)
			return levels[i].level;
	}
	return -1;
}

int main (int ac, char **av) {
	if (ac != 2)
		return std::cerr << "Usage : <complaining_level> (DEBUG, INFO, WARNING, ERROR)", -1;

	Harl	compliner;

	std::string	name = av[1];
	int			level = getLevel(name);
	if (level == -1) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}

	switch (level) {
		case 0:
			std::cout << "[ DEBUG ]\n";
			compliner.complain("DEBUG");
			std::cout << "\n";
		case 1:
			std::cout << "[ INFO ]\n";
			compliner.complain("INFO");
			std::cout << "\n";
		case 2:
			std::cout << "[ WARNING ]\n";
			compliner.complain("WARNING");
			std::cout << "\n";
		case 3:
			std::cout << "[ ERROR ]\n";
			compliner.complain("ERROR");
			std::cout << "\n";
	};

	return 0;
}
