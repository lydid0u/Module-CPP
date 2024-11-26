#ifndef FragTRAP_HPP
# define FragTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public :
        FragTrap(std::string name);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys();
};

#endif               