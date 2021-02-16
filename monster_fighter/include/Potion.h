#ifndef POTION_H
#define POTION_H 

#include "Player.h"


class Potion {
public:
    enum class Type{
        HEALTH,
        STRENTH,
        POISON,
        max_types
    };

private:
    Potion::Type m_type {};
    int m_size {};

public:

    Potion(Type type=Type::HEALTH)
        : m_type{type} {}; 

    int getSize() const;
    std::string_view getSizeLabel() const;
    void drinkPotion(Player &player) const;
};



#endif /* ifndef POTION_H */
