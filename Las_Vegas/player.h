#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

class Player{
    int num_;
    unsigned diceStock_;
    unsigned sumAccount_;
    std::vector<unsigned>dices_;

public:
    inline Player (int no, unsigned dices = 8, unsigned bank = 0);
    inline void creditP (unsigned value);
    inline unsigned getSumAccount() const;
    inline unsigned getDiceStock() const;
    inline void putDice(unsigned num);
    inline void getDiceBack();
    void rollDices();
    inline unsigned getDiceAt(unsigned pos)const;
    unsigned valueOccurency(unsigned val)const;
};

Player::Player(int no, unsigned dices, unsigned bank)
    :num_(no), diceStock_(dices), sumAccount_(bank){
    for (int i=0; i<8; i++){
        dices_.push_back(1);
    }
}

void Player::creditP(unsigned value){
    sumAccount_ += value;
}

unsigned Player::getSumAccount()const{
    return sumAccount_;
}

unsigned Player::getDiceStock()const{
    return diceStock_;
}

void Player::putDice(unsigned num){
    diceStock_ -= num;
}

void Player::getDiceBack(){
    diceStock_ = 8;
}

unsigned Player::getDiceAt(unsigned pos) const{
    return dices_[pos];
}

#endif // PLAYER_H
