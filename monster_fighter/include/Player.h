#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : public Creature{
private:
    int m_lvl {};
public:
    Player(std::string name)
        : Creature{name, '@', 10, 1, 0}{}

    int getLvl () const; 

    void levelUp();
    void printStatus ()const ;
};

#endif /* ifndef PLAYER_H */
