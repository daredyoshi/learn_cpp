#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <random>

//
// bool playBlackjack(const deck_type& deck){
//     Card const *topCard = &deck[0];
//     Card const *dealerCard1 = drawCard(topCard);
//     Card const *dealerCard2 = drawCard(topCard);
//     std::cout << "The dealer's open card is \n";
//     printCard(*dealerCard1);
//     std::cout << '\n';
//     // printCard(*dealerCard2); // this card it not yet visible to player
//     std::string choice; // this will be either hit or stand
//    
//     std::vector<Card const *> dealerDeck{dealerCard1, dealerCard2};
//     
//
//     std::vector<Card const *> playerDeck{};
//     Card const *playerCard1 = drawCard(topCard);
//     playerDeck.push_back(playerCard1);
//
//     unsigned short score {getCardValue(*playerCard1)};
//     unsigned short dealerKnownScore {getCardValue(*dealerCard1)};
//
//     
//     while(choice != "stand"){
//         Card const *playerCard = drawCard(topCard);
//         
//         if(dealerKnownScore < dealerTargetScore){
//             Card const *dealerCard = drawCard(topCard);
//             dealerDeck.push_back(dealerCard);
//             dealerKnownScore += getCardValue(*dealerCard);
//         }
//
//         playerDeck.push_back(playerCard);
//         score += getCardValue(*playerCard);
//
//         std::cout << "Your cards so far are:\n";
//         
//         for(Card const *card : playerDeck){
//
//             printCard(*card);
//             std::cout << '\n';
//         }
//         if(score < targetScore){
//             std::cout << "You score so far is " << score << '\n';
//             do{                                              
//                std::cout << "Will you hit or stand?i\n";     
//                std::getline(std::cin, choice);               
//            }while(choice != "hit" && choice != "stand");
//         }
//         else{
//             break;
//         }
//     }
//
//     // turn over the covered dealer card 2
//     dealerKnownScore += getCardValue(*dealerCard2);
//
//     std::cout << "Player Score = " << score << "\n";
//     std::cout << "Dealer Score = " << dealerKnownScore<< "\n";
//
//     if(score > targetScore){
//         return false; // you lost
//     }
//     
//     if(dealerKnownScore > targetScore){
//         return true; // the dealer lost 
//     }
//
//     if(score <= dealerKnownScore){
//         return false;
//     }
//     else{
//         return true;
//     }
//
//     return true;
// }
//
// int main (){
//     deck_type deck{ createDeck() };
//
//     // std::cout << deck;
//     // std::cout << " Now print the shuffled dect : \n";
//     shuffleDeck(deck);
//     // Card firstCard = deck[0];
//     // std::cout << "The First card of the deck is ";
//     // printCard(firstCard);
//     // std::cout << " and has a value of " << getCardValue(firstCard) << " \n";
//     bool win {playBlackjack(deck)};
//     if(win){
//         std::cout << "You won!";
//     }
//     else{
//         std::cout << "Sorry you lost";
//     }
//     return 0;
// }
//
//


//
