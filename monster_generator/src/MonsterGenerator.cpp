
#include "MonsterGenerator.h"

constexpr int MAX_HP {100};


Monster  MonsterGenerator::generateMonster() {

    static constexpr std::array m_names {
        "George", "Fred", "Mr. Senrorita", 
            "Krax", "Marina", "Kelly"
    };
    static constexpr std::array m_roars {
        "*croak*", "ARARARHARARH", "*thump*",
            "*whistle*", "Good Evening", "My GOLLY GOSH" 
    };
    std::string name = m_names[getRandomNumber(0, m_names.size()-1)];
    std::string roar = m_roars[getRandomNumber(0, m_roars.size()-1)];
    int hp = getRandomNumber(0, MAX_HP);
    int max_types {static_cast<int>(Monster::Type::max_monster_types)};
    Monster::Type type = static_cast<Monster::Type>(getRandomNumber(0, max_types-1));
    return {type, name, roar, hp};
}

int MonsterGenerator::getRandomNumber(int min, int max) {
    static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  // static used for efficiency, so we only calculate this value once
            // evenly distribute the random number across our range
    return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
}



