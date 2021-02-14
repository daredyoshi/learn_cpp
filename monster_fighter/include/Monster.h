#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
#include "Player.h"
#include <iostream>

class Monster : public Creature{

public:
    enum class Type{
        DRAGON,
        ORC,
        SLIME,
        max_types
    };
    Monster(Monster::Type type, std::string name, char symbol, int hp, int attack, int gold)
        : Creature{name, symbol, hp, attack, gold}, m_type{type} {

        } 


protected:
    Monster::Type m_type {};
};

class Dragon : public Monster{

public:
    Dragon()
        : Monster(Monster::Type::DRAGON, "dragon", 'D', 20, 4, 100){

        }
};

class Orc: public Monster{
public:
    Orc()
        : Monster(Monster::Type::ORC, "orc", 'o', 4, 2, 25){

        }
};

class Slime: public Monster{
public:
    Slime()
        : Monster(Monster::Type::SLIME, "slime", 's', 1, 1, 10){

        }
};

#endif /* ifndef MONSTER_H

class Monster{

};
 */
