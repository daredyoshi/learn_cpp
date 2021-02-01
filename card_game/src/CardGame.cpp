#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <random>


enum class CardRank{
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,

    max_ranks
};

enum class CardSuit{
    clubs,
    diamonds,
    hearts,
    spades,

    max_suits
};

constexpr int targetScore {21};
constexpr int dealerTargetScore  {10};

struct Card{
    CardRank rank{};
    CardSuit suit{};
};


using deck_type = std::array<Card, 52>;

void printCard(const Card& card){
    char str[2] {};
    
    switch(card.rank){
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

    switch(card.suit){
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




deck_type createDeck(){
    deck_type deck {};
    deck_type::size_type card_idx {0};
    for(int r { 0 }; r < static_cast<int>(CardRank::max_ranks); ++r){
        for(int s { 0 }; s < static_cast<int>(CardSuit::max_suits); ++s){
            deck[card_idx].suit = static_cast<CardSuit>(s);
            deck[card_idx].rank = static_cast<CardRank>(r); 
            ++card_idx;
        }
    }
    return deck;
}

void printDeck(const deck_type& deck){
    for(const auto& card : deck){
        printCard(card);
    }
    std::cout << '\n';
}

void shuffleDeck(deck_type& deck){
    std::random_device rd;
    static std::mt19937 g(rd());

    std::shuffle(deck.begin(), deck.end(), g);
}

unsigned short getCardValue(Card card){
    switch(card.rank){
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

// this takes a pointer to the current "Top Card"
// of the deck, increments it, and returns a pointer to the 
// previous top card. This is intended to simulate drawing from 
// the deck
//
// This function is badly written because it could loop out of 
// the range of the array. Because there's no chance the single
// game will ever draw that many cards we are safe. But ideally
// you would pass the length of the deck and shuffle if no cards are left

const Card* drawCard(Card const*& topCard){
    Card const *card =&( *topCard);

    ++topCard;
    return card;
}


bool playBlackjack(const deck_type& deck){
    Card const *topCard = &deck[0];
    Card const *dealerCard1 = drawCard(topCard);
    Card const *dealerCard2 = drawCard(topCard);
    std::cout << "The dealer's open card is \n";
    printCard(*dealerCard1);
    std::cout << '\n';
    // printCard(*dealerCard2); // this card it not yet visible to player
    std::string choice; // this will be either hit or stand
   
    std::vector<Card const *> dealerDeck{dealerCard1, dealerCard2};
    

    std::vector<Card const *> playerDeck{};
    Card const *playerCard1 = drawCard(topCard);
    playerDeck.push_back(playerCard1);

    unsigned short score {getCardValue(*playerCard1)};
    unsigned short dealerKnownScore {getCardValue(*dealerCard1)};

    
    while(choice != "stand"){
        Card const *playerCard = drawCard(topCard);
        
        if(dealerKnownScore < dealerTargetScore){
            Card const *dealerCard = drawCard(topCard);
            dealerDeck.push_back(dealerCard);
            dealerKnownScore += getCardValue(*dealerCard);
        }

        playerDeck.push_back(playerCard);
        score += getCardValue(*playerCard);

        std::cout << "Your cards so far are:\n";
        
        for(Card const *card : playerDeck){

            printCard(*card);
            std::cout << '\n';
        }
        if(score < targetScore){
            std::cout << "You score so far is " << score << '\n';
            do{                                              
               std::cout << "Will you hit or stand?i\n";     
               std::getline(std::cin, choice);               
           }while(choice != "hit" && choice != "stand");
        }
        else{
            break;
        }
    }

    // turn over the covered dealer card 2
    dealerKnownScore += getCardValue(*dealerCard2);

    std::cout << "Player Score = " << score << "\n";
    std::cout << "Dealer Score = " << dealerKnownScore<< "\n";

    if(score > targetScore){
        return false; // you lost
    }
    
    if(dealerKnownScore > targetScore){
        return true; // the dealer lost 
    }

    if(score <= dealerKnownScore){
        return false;
    }
    else{
        return true;
    }

    return true;
}

int main (){
    deck_type deck{ createDeck() };

    // std::cout << deck;
    // std::cout << " Now print the shuffled dect : \n";
    shuffleDeck(deck);
    // Card firstCard = deck[0];
    // std::cout << "The First card of the deck is ";
    // printCard(firstCard);
    // std::cout << " and has a value of " << getCardValue(firstCard) << " \n";
    bool win {playBlackjack(deck)};
    if(win){
        std::cout << "You won!";
    }
    else{
        std::cout << "Sorry you lost";
    }
    return 0;
}





