#include "Monster.h"
#include <iostream>
#include <string>



// convert the monster type into a string
std::string_view Monster::getTypeString() const {
    switch (m_type) {
        case Type::ogre:
            return "Ogre";
        case Type::dragon:
            return "Dragon";
        case Type::orc:
            return "Orc";
        case Type::giant_spider:
            return "Giant Spider";
        case Type::slime:
            return "Slime";
        case Type::skeleton:
            return "Skeleton";
        case Type::troll:
            return "Troll";
        case Type::zombie:
            return "Zombie";
        case Type::goblin:
            return "Gobline";
        default:
            return "Unknown Type";    
    }
}

void Monster::print() const {
    std::cout << m_name << " the " << getTypeString() << " has " 
        << m_hitPoints << " hit points and says " << m_roar << '\n';
}

