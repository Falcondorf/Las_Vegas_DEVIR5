#ifndef CASINO_H
#define CASINO_H

#include <vector>

class Casino{
    unsigned num_;
    std::vector<unsigned> ticketList_;
    std::vector<unsigned> betList_;
public:
    inline Casino(unsigned n);
    inline unsigned getNum() const;
    inline void creditTicket(unsigned value);
    unsigned debitHigherTicket();
    inline unsigned totalMoney();
    inline void insertBet(unsigned valAdd, int numPlayer);
    void resetCasino();

};

Casino::Casino(unsigned n):num_(n){}

unsigned Casino::getNum()const{
    return num_;
}

void Casino::creditTicket(unsigned value){
    ticketList_.push_back(value);
}

void Casino::insertBet(unsigned valAdd, int numPlayer){
    betList_[numPlayer-1] += valAdd;
}

unsigned Casino::totalMoney(){
    unsigned total;
    for(unsigned val : ticketList_){
        total += val;
    }
    return total;
}

#endif // CASINO_H
