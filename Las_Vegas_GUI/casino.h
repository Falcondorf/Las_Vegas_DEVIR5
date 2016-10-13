#ifndef CASINO_H
#define CASINO_H

#include <vector>
#include <string>

#include "subject.h"

class Casino{
    unsigned num_;
    std::vector<unsigned> ticketList_;
    std::vector<unsigned> betList_;


public:
    inline Casino(unsigned n);
    inline unsigned getNum() const;
    void initBetList(unsigned nbP);
    inline void creditTicket(unsigned value);
    unsigned debitHigherTicket();
    inline unsigned totalMoney();
    inline void insertBet(unsigned valAdd, int numPlayer);
    void resetCasino();
    std::string makeStringTickets();
    std::string makeStringBets();

};

Casino::Casino(unsigned n):num_(n){}

unsigned Casino::getNum()const{
    return num_;
}

void Casino::creditTicket(unsigned value){
    ticketList_.push_back(value);
}

void Casino::insertBet(unsigned valAdd, int numPlayer){
    betList_[numPlayer] += valAdd;
}

unsigned Casino::totalMoney(){
    unsigned total=0;
    for(unsigned val : ticketList_){
        total += val;
    }
    return total;
}

#endif // CASINO_H
