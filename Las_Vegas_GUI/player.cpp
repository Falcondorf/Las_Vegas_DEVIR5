#include "player.h"
#include <exception>
#include <random>
#include <ctime>

void Player::rollDices(){
    if (diceStock_==0) throw std::exception();
    std::srand(unsigned(std::time(0)));
    for (unsigned i=0; i<diceStock_;i++){
        dices_[i]=(std::rand()%6+1);
    }
    bigDice_.second = (std::rand()%6+1);
}

unsigned Player::valueOccurency(unsigned val) const{
    unsigned count = 0;
    unsigned normalStock;
    if (bigDiceExtension_){
        normalStock = getDiceStock()-1;
    } else {
        normalStock = getDiceStock();
    }
    for(unsigned i=0; i< normalStock;i++){
        if (dices_.at(i)==val){
            count++;
        }
    }
    if (bigDice_.first && bigDice_.second == val){
        count += 2;
    }
    return count;
}
