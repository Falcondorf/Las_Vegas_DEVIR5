#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "subject.h"

class Player{
    int num_;
    bool bigDiceExtension_;
    std::pair<bool, unsigned> bigDice_;
    unsigned diceStock_;
    unsigned sumAccount_;
    std::vector<unsigned>dices_;

public:
    inline Player (int no, bool ext = false, unsigned dices = 8, unsigned bank = 0);
    inline unsigned getNum() const;
    inline void creditP (unsigned value);
    inline unsigned getSumAccount() const;
    inline unsigned getDiceStock() const;
    inline void putDice(unsigned num, bool putBig);
    inline void getDiceBack();
    void rollDices();
    inline unsigned getDiceAt(unsigned pos)const;
    unsigned valueOccurency(unsigned val)const;
    inline bool getBigDiceExt() const;
    inline bool getHasBigDice() const;
    inline unsigned getBigDiceVal() const;
};

Player::Player(int no, bool ext, unsigned dices, unsigned bank)
    :num_(no), bigDiceExtension_(ext), sumAccount_(bank){
    if (bigDiceExtension_){
        diceStock_ = dices-1;
        bigDice_.first = true;
        bigDice_.second = 1;
    } else {
        diceStock_ = dices;
        bigDice_.first = false;
        bigDice_.second = 0;
    }
    for (unsigned i=0; i<diceStock_; i++){
        dices_.push_back(1);
    }
}

unsigned Player::getNum() const{
    return num_;
}

bool Player::getBigDiceExt() const{
    return bigDiceExtension_;
}

bool Player::getHasBigDice() const{
    return bigDice_.first;
}

unsigned Player::getBigDiceVal() const{
    return bigDice_.second;
}

void Player::creditP(unsigned value){
    sumAccount_ += value;
}

unsigned Player::getSumAccount()const{
    return sumAccount_;
}

unsigned Player::getDiceStock()const{
    if(bigDice_.first){
        return diceStock_+1;
    }else{
        return diceStock_;
    }
}

void Player::putDice(unsigned num, bool putBig){
    diceStock_ -= num;
    if (putBig){
        bigDice_.first = false;
    }
}

void Player::getDiceBack(){
    if (bigDiceExtension_){
        diceStock_ = 7;
        bigDice_.first = true;
    }else {
        diceStock_ = 8;
    }
}

unsigned Player::getDiceAt(unsigned pos) const{
    return dices_[pos];
}

#endif // PLAYER_H
