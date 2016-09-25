#ifndef PLAYER_H
#define PLAYER_H


class Player{
    unsigned num_;
    unsigned diceStock_;
    unsigned sumAccount_;

public:
    inline Player (unsigned no, unsigned dices = 8, unsigned bank = 0);
    inline void creditP (unsigned value);
    inline unsigned getSumAccount() const;
    inline unsigned getDiceStock() const;
    inline void putDice(unsigned num);
    inline void getDiceBack();
};

Player::Player(unsigned no, unsigned dices, unsigned bank)
    :num_(no), diceStock_(dices), sumAccount_(bank){}

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

#endif // PLAYER_H
