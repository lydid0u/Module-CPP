#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie RandomZombie(name);
    RandomZombie.announce();
}