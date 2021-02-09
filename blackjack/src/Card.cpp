#include "Card.h"
#include <iostream>


void Card::print() const {
    char str[2] {};

    switch(m_rank){
        case CardRank::ace:
            str[0] = 'A';
            break;
        case CardRank::king:
            str[0] = 'K';
            break;
        case CardRank::queen:
            str[0] = 'Q';
            break;
        case CardRank::jack:
            str[0] = 'J';
            break;
        case CardRank::ten:
            str[0] = 'T';
            break;
        case CardRank::nine:
            str[0] = '9';
            break;
        case CardRank::eight:
            str[0] = '8';
            break;
        case CardRank::seven:
            str[0] = '7';
            break;
        case CardRank::six:
            str[0] = '6';
            break;
        case CardRank::five:
            str[0] = '5';
            break;
        case CardRank::four:
            str[0] = '4';
            break;
        case CardRank::three:
            str[0] = '3';
            break;
        case CardRank::two:
            str[0] = '2';
            break;
        default:
            str[0] = '0';
            break;
    };
    switch(m_suit){
        case CardSuit::clubs:
            str[1] = 'C';
            break;
        case CardSuit::diamonds:
            str[1] = 'D';
            break;
        case CardSuit::hearts:
            str[1] = 'H';
            break;
        case CardSuit::spades:
            str[1] = 'S';
            break;
        default:
            str[1] = '0';
            break;
    };
    std::cout << str << " ";
}

unsigned short Card::value() const{
    switch(m_rank){
        case CardRank::ace:
            return 11;
        case CardRank::king: 
        case CardRank::queen:
        case CardRank::jack: 
        case CardRank::ten:
            return 10;
        case CardRank::nine:
            return 9;
        case CardRank::eight:
            return 8;
        case CardRank::seven:
            return 7;
        case CardRank::six:
            return 6;
        case CardRank::five:
            return 5;
        case CardRank::four:
            return 4;
        case CardRank::three:
            return 3;
        case CardRank::two:
            return 2;
        default:
            return 0;
        };
}





