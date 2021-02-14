#include "Creature.h"


const std::string& Creature::getName() const{ return m_name; }
char Creature::getSymbol() const{ return m_symbol; }
int Creature::getHp() const { return m_hp; }
int Creature::getAttack() const{ return m_attack; }
int Creature::getGold() const{ return m_gold; }

void Creature::reduceHealth(int damage){
    m_hp -= damage;
}

bool Creature::isDead() const {
    return m_hp <= 0;
}

void Creature::addGold(int gold){
    m_gold+=gold;
}



