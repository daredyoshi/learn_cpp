#include "Player.h"
#include <iostream>

int Player::getLvl() const { return m_lvl; }

void Player::levelUp(){
    ++m_lvl;
    ++m_attack;    
}

void Player::printStatus() const {
    std::cout << "You have " << m_hp << " health and are carrying "
        << m_gold << " gold.\n";
}






