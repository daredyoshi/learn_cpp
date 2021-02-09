
#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"
#include <vector>

using player_deck_type = std::vector<Card>;


class Player{
private:
    player_deck_type m_deck {};
    unsigned short m_score {0};
public:
    
    void drawCard(Deck &deck);
    bool isBust ()const ;
    void printDeck() const;
    unsigned short getScore() const{
        return m_score;
    };
    

};

#endif 
