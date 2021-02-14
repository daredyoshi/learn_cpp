#include "Potion.h"
#include "Player.h"
#include <iostream>

int Potion::getSize() const { return m_size; }

void Potion::drinkPotion(Player &player) const{
    int healing {};
    switch(m_type){
        case Potion::Type::STRENTH:
            player.levelUp();
            std::cout << "You leveled up!\n"; 
            return;
        case Potion::Type::POISON:
            player.reduceHealth(1);
            std::cout << "The poition hurts you for 1 hp\n";
            return;
        case Potion::Type::HEALTH:
            healing = ( m_size * 2 ); 
            player.reduceHealth(-healing) ;
            std::cout << "The potion heals you for " << healing << '\n';
            return;
        default:
            return;
    };
}

std::string Potion::getSizeLabel() const{
    switch(m_size){
        case 0:
            return "small";
        case 1:
            return "medium";
        case 2:
            return "large";
            return "huge";
        default:
            if (m_size > 0){
                return "huge";
            }
            else{
                return "unknown";
            }
    };
}
