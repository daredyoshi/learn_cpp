#include "Card.h"
#include <iostream>


void Card::print() const {
    char str[2] {};
    if(m_rank >= CardRank::max_ranks) {
        str[0] = '?';
    }
    else{
        str[0] = "23456789TJQKA"[static_cast<int>(m_rank)];
    }

    if(m_suit >= CardSuit::max_suits){
        str[1] = '?';
    }
    else{
        str[1] = "CDHS"[static_cast<int>(m_suit)];
    }
    std::cout << str << " ";
}

unsigned char Card::value() const{
    if(m_rank >= CardRank::max_ranks){
        return '?';
    }
    else{
        using u8 = unsigned char[];
        return u8{2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 
        10, 10, 11}[static_cast<int>(m_rank)];

    }
}





