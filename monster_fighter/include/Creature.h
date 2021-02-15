#ifndef CREATURE_H
#define CREATURE_H

#include<string>


class Creature{
protected:
    std::string m_name {};
    char m_symbol {};
    int m_hp {};
    int m_attack {};
    int m_gold {};

public:
    Creature(std::string name, char symbol, int hp, int attack, int gold )
        : m_name{name}, m_symbol{symbol}, m_hp{hp}, m_attack{attack}, m_gold{gold}{

    }

    const std::string& getName() const;
    char getSymbol() const;
    int getHp() const;
    int getAttack() const;
    int getGold() const;

    void reduceHealth(int damage);
    bool isDead() const;
    void addGold(int gold);
    
};

#endif /* ifndef CREATURE_H

}
 */
