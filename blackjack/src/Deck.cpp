#include "Deck.h"
#include <iostream>
#include <random>
#include <algorithm>

Deck::Deck(){
    deck_type::size_type card_idx {0};
    for(int r { 0 }; r < static_cast<int>(CardRank::max_ranks); ++r){
        for(int s { 0 }; s < static_cast<int>(CardSuit::max_suits); ++s){
            m_deck[card_idx] = Card{
                static_cast<CardRank>(r),
                static_cast<CardSuit>(s)
            };
            ++card_idx;
        }
    }
}

void Deck::print() const{
    for(const auto& card : m_deck){
        card.print();
    }
    std::cout << '\n';
}


void Deck::shuffle(){
    std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(m_deck.begin(), m_deck.end(), g);
    m_cardIndex = 0;
}

const Card& Deck::dealCard() {
    // Automatically shuffle if you reach the bottom of
    // the deck
    if(m_cardIndex > DECK_SIZE ){
        shuffle();
    }
    return m_deck[m_cardIndex++]; 
}

