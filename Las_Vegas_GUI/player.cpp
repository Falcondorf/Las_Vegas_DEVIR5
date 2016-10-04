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
}

unsigned Player::valueOccurency(unsigned val) const{
    unsigned count = 0;
    for(unsigned ud: dices_){
        if (ud==val){
            count++;
        }
    }
    return count;
}
