#include <ios>
#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <random>
#include "Monster.h"
#include "MonsterGenerator.h"

// namespace constants{
//     constexpr int maxHp { 5000 };
// }
//
// enum class MonsterColor{
//     red,
//     blue, 
//     green,
//     yellow, 
//     purble,
//     shiny,
//     count
// };
//
//
//
// std::string getMonsterColorName(MonsterColor color){
//     switch (color) {
//         case MonsterColor::red:
//             return "Red";
//         case MonsterColor::blue:
//             return "Blue";
//         case MonsterColor::green:
//             return "Green";
//         case MonsterColor::yellow:
//             return "Yellow";
//         case MonsterColor::purble:
//             return "Purble";
//         case MonsterColor::shiny:
//             return "Shiny XXS";
//         default:
//             return "Invisible";    
//     }
// }
//
//
// Monster getRandomMonster(std::string name){
//
//     // initialize our mersenne twister with a random seed based on the clock 
//     std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
//     
//     // Create a reusable random number generator that generates uniform numbers betwen 1 
//     // and the length of the monter type class
//     //
//     std::uniform_int_distribution type_gen{0, static_cast<int>(MonsterType::count)-1};
//     std::uniform_int_distribution color_gen{0, static_cast<int>(MonsterColor::count)-1};
//     std::uniform_int_distribution hp_gen{1, constants::maxHp};
//     MonsterType type {type_gen(mersenne)}; 
//     MonsterColor color {color_gen(mersenne)};
//     int hp = hp_gen(mersenne);
//
//     return Monster {type, color, name, hp};
// }

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();
    Monster m{ MonsterGenerator::generateMonster()} ;
    m.print();
}
