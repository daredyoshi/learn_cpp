
#ifndef DECK_H
#define DECK_H 

#include "Card.h"
#include "const.h"
#include <array>

using deck_type = std::array<Card, DECK_SIZE>;

class Deck{
private:
    deck_type m_deck;
    deck_type::size_type m_cardIndex{0};

public:
    Deck();
    void print() const;
    void shuffle();
    const Card& dealCard();


};



#endif /* ifndef DECK_H */


