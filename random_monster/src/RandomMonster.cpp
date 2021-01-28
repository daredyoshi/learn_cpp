#include <ios>
#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <random>

namespace constants{
    constexpr int maxHp { 5000 };
}

enum class MonsterColor{
    red,
    blue, 
    green,
    yellow, 
    purble,
    shiny,
    count
};

enum class MonsterType{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
    skeleton,
    count
};


struct Monster{
    MonsterType type;
    MonsterColor color;
    std::string name;
    int hp;
};


std::string getMonsterColorName(MonsterColor color){
    switch (color) {
        case MonsterColor::red:
            return "Red";
        case MonsterColor::blue:
            return "Blue";
        case MonsterColor::green:
            return "Green";
        case MonsterColor::yellow:
            return "Yellow";
        case MonsterColor::purble:
            return "Purble";
        case MonsterColor::shiny:
            return "Shiny XXS";
        default:
            return "Invisible";    
    }
}

// convert the monster type into a string
std::string getMonsterTypeName(MonsterType type){
    switch (type) {
        case MonsterType::ogre:
            return "Ogre";
        case MonsterType::dragon:
            return "Dragon";
        case MonsterType::orc:
            return "Orc";
        case MonsterType::giant_spider:
            return "Giant Spider";
        case MonsterType::slime:
            return "Slime";
        case MonsterType::skeleton:
            return "Skeleton";
        default:
            return "Unknown Type";    
    }
}

Monster getRandomMonster(std::string name){

    // initialize our mersenne twister with a random seed based on the clock 
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    
    // Create a reusable random number generator that generates uniform numbers betwen 1 
    // and the length of the monter type class
    //
    std::uniform_int_distribution type_gen{0, static_cast<int>(MonsterType::count)-1};
    std::uniform_int_distribution color_gen{0, static_cast<int>(MonsterColor::count)-1};
    std::uniform_int_distribution hp_gen{1, constants::maxHp};
    MonsterType type {type_gen(mersenne)}; 
    MonsterColor color {color_gen(mersenne)};
    int hp = hp_gen(mersenne);

    return Monster {type, color, name, hp};
}

int main()
{
    std::string name{};

    std::cout <<  "Please enter the desired name of your monster: \n";
    std::getline(std::cin, name);
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Monster monster = getRandomMonster(name);

    std::cout << "You have created a " << getMonsterColorName(monster.color) << " " 
        << getMonsterTypeName(monster.type) << " called " << monster.name << " with " << monster.hp << " hit points. \n"; 

    return 0;
}
