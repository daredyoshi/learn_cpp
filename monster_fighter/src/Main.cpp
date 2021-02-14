#include <iostream> 
#include <ctime>
#include <string>
#include "Creature.h"
#include "Player.h"
#include "Potion.h"
#include "Monster.h"
#include "const.h"

Monster getMonster(Monster::Type type){
    switch (type){
        case Monster::Type::SLIME:
            return Slime();
        case Monster::Type::DRAGON:
            return Dragon();
        case Monster::Type::ORC:
            return Orc();
        default:
            return Slime();
    }
}

int getRandomNumber(int min, int max) {                                
   static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  // s
           // evenly distribute the random number across our range                       
   return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);             
}

Monster getRandomMonster(){
    int max_types {static_cast<int>(Monster::Type::max_types)};                   
    Monster::Type type = static_cast<Monster::Type>(getRandomNumber(0, max_types-1));  
    return Monster{getMonster(type)};
}

void monsterAttack(Player &player, Monster &m){
    player.reduceHealth(m.getAttack());
    std::cout << "The " << m.getName() << " hit you for " << m.getAttack() << " damage.\n";
    if(player.isDead()){
            std::cout << "You died at level " << player.getLvl() << " with " << player.getGold() << " gold.\n";
            std::cout << "Too bad you can't take it with you!";
        }
    else{
        std::cout << "You now have " << player.getHp() << " hit points. \n";
    }

}

void findPotion(Player &player){
    Potion::Type potionType {static_cast<Potion::Type>(getRandomNumber(0, static_cast<int>(Potion::Type::max_types) - 1))}; 
    Potion potion {potionType};
    std::cout << "You found a " << potion.getSizeLabel() << " potion. Drink it? (y), (n)\n";
    char choice {};
    do{
        std::cin >> choice;
    }while(choice != 'y' && choice != 'n');

    if(choice == 'y'){
        potion.drinkPotion(player);
    }
}

void fightMonster(Player &player, Monster &m){ 
    m.reduceHealth(player.getAttack());
    std::cout << "You hit the " << m.getName() << " for " << player.getAttack() << " damage.\n";
    if(m.isDead()){
        player.levelUp();
        player.addGold(m.getGold());
        std::cout << "You are now at level " << player.getLvl() << '\n';
        std::cout << "You found " << m.getGold() << " gold.\n";
        int randNum {getRandomNumber(0, 100)}; 

        if(randNum <= POTION_FIND_PERCENTAGE){
            findPotion(player);
        }
    }
    else{
        monsterAttack(player, m);
    }
}



void playGame(Player &player){

    Monster m  {getRandomMonster()};
    std::cout << "You have encountered a " << m.getName()<< '\n'; 

    bool escaped{false};
    do{
        std::cout << "(r)un or (f)ight: ";
        char choice {};
        std::cin >> choice; if(choice == 'r'){ escaped = getRandomNumber(0, 1);
            if(escaped){
                std::cout << "You have successfully fled. \n";
            }
            else{
                std::cout << "You failed to flee \n";
                monsterAttack(player, m);
            }
        }
        if(choice == 'f'){
            fightMonster(player, m);
        }    
        if(player.isDead()){
            break; // oof
        }
    }while(!m.isDead() && !escaped );
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    std::cout << "Enter your name: \n";
    std::string name {};
    std::getline(std::cin, name);
    std::cout << "Welcome, " << name << '\n';

    Player player {name};
    player.printStatus();

    do{
        playGame(player);    
    }while (player.getLvl() < 20 && !player.isDead() );

    

	return 0;
}
