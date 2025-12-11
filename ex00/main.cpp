#include <Zombie.hpp>
#include <iostream>

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);



int main(void) {
	std::cout << "-Invoking a random zombie..." << std::endl;
	randomChump("hamid");

	std::cout << "-As we can see, we didn't have to call any function to destroy this zombie." << std::endl;
	std::cout << "That's because it was allocated on the stack, so its lifetime ended" << std::endl;
	std::cout << "automatically when the function randomChump() returned." << std::endl;

	std::cout << "-Now let's create a zombie using newZombie()..." << std::endl;

	Zombie* zombie = newZombie("missi");

	std::cout << "-Unlike the first one, this zombie is still alive after the function returns." << std::endl;
	std::cout << "This is because newZombie() allocates the zombie on the heap, giving it a longer lifetime" << std::endl;
	std::cout << "that we must manage manually. We can interact with it, make it announce itself, like that;" << std::endl;

	zombie->annouce();

	std::cout << "and decide exactly when its lifetime should end." << std::endl;
	std::cout << "For example, we can now destroy this zombie ourselves by calling delete:" << std::endl;

	delete zombie;

	std::cout << "-The zombie has now been destroyed manually. This demonstrates the difference between" << std::endl;
	std::cout << "stack allocation (short, automatic lifetime) and heap allocation (manual, controlled lifetime)." << std::endl;
}


