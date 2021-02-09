#include "Card.h"
#include "Deck.h"
#include "const.h"
#include "Player.h"
#include <iostream>

bool playBlackjack(Deck &deck, Player &player, Player &dealer){
    dealer.drawCard(deck);


    std::cout << "The dealer's open card is \n";
    dealer.printDeck(); 
    // printCard(*dealerCard2); // this card it not yet visible to player
    std::string choice; // this will be either hit or stand


    player.drawCard(deck);

    while(choice != "stand"){
        player.drawCard(deck);

        if(dealer.getScore() < DEALER_QUIT_SCORE){
            dealer.drawCard(deck);
        }

        std::cout << "Your cards so far are:\n";
        player.printDeck();
        
        unsigned short playerScore = player.getScore();
        if(playerScore < TARGET_SCORE){
            std::cout << "You score so far is " << playerScore << '\n';
            do{                                              
               std::cout << "Will you hit or stand?\n";     
               std::getline(std::cin, choice);               
           }while(choice != "hit" && choice != "stand");
        }
        else{
            break;
        }
    }

    // turn over the covered dealer card 2
    dealer.drawCard(deck);

    unsigned short playerScore = player.getScore();
    unsigned short dealerScore = dealer.getScore();

    std::cout << "Player Score = " << player.getScore() << "\n";
    std::cout << "Dealer Score = " << dealer.getScore() << "\n";

    if(playerScore > TARGET_SCORE){
        return false; // you lost
    }

    if(dealerScore > TARGET_SCORE){
        return true; // the dealer lost 
    }

    if(playerScore <= dealerScore){
        return false;
    }
    else{
        return true;
    }

    return true;
}

int main (){
    
    Deck deck{};
    deck.shuffle();


    Player player{};
    Player dealer{};
    
    bool win {playBlackjack(deck, player, dealer)};
    if(win){
        std::cout << "You won!\n";
    }
    else{
        std::cout << "Sorry you lost\n";
    }
    std::cout << "Your hand was: \n";
    player.printDeck ();

    std::cout << "The dealer's hand was: \n"; 
    dealer.printDeck();
    return 0;
}
