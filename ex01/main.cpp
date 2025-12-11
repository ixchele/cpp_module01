#include <Zombie.hpp>
#include <iostream>

#define HORDE_SIZE 6

Zombie* zombieHorde(int N, std::string name);

int main(void) {
    std::cout << "Creating a horde of zombies with size " << HORDE_SIZE << "..." << std::endl;

    Zombie* zombie_horde = zombieHorde(HORDE_SIZE, "Hamid");

    std::cout << "The horde has been created. Each zombie will now announce itself:" << std::endl;

    for (int i = 0; i < HORDE_SIZE; ++i) {
        std::cout << "Zombie #" << i + 1 << ": ";
        zombie_horde[i].announce();
    }

    std::cout << "All zombies have announced themselves." << std::endl;
    std::cout << "Since they were allocated on the heap, we must manually deallocate them." << std::endl;

    delete[] zombie_horde;

    std::cout << "Horde deleted. All heap-allocated zombies are now destroyed." << std::endl;
    std::cout << "Note: If zombies were created on the stack, they would be automatically destroyed when going out of scope." << std::endl;

    return 0;
}
