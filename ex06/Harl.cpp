#include <Harl.hpp>
#include <iostream>

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

struct	dispatch {
	std::string	level;
	void	(Harl::*f)(void);
};

void	Harl::complain(std::string level) {
	dispatch	Table[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
		{std::string(), NULL},
	};
	
	for (size_t i = 0; !Table[i].level.empty(); ++i) {
		 if (!level.compare(0, level.size(), Table[i].level))
			(this->*(Table[i].f))();
	}
}
