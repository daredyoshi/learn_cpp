#include "Player.h"
#include "Deck.h"
#include "const.h"

#include <iostream>

void Player::drawCard(Deck &deck){
    Card card = deck.dealCard();
    m_deck.push_back(card);
    m_score += card.value();
}

bool Player::isBust () const{
    return m_score >= TARGET_SCORE ;
}

void Player::printDeck() const{
    for(const auto& card : m_deck){
        card.print();
    }
    std::cout << '\n';
}
