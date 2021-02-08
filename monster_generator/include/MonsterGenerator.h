
#ifndef MONSTER_GENERATOR
#define MONSTER_GENERATOR 

#include "Monster.h"
#include <array>

class MonsterGenerator{
public:
    static Monster generateMonster();
    static int getRandomNumber(int min, int max);
};

#endif /* ifndef MONSTER_GENERATOR */
